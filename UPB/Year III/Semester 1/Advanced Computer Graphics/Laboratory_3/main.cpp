// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Include GLEW
#include "dependente\glew\glew.h"

// Include GLFW
#include "dependente\glfw\glfw3.h"

// Include GLM
#include "dependente\glm\glm.hpp"
#include "dependente\glm\gtc\matrix_transform.hpp"
#include "dependente\glm\gtc\type_ptr.hpp"

#include "shader.hpp"

//variables
GLFWwindow* window;
const int width = 1024, height = 1024;
float sx = 1.5f, sy = 0.5f, sz = 0;


int main(void)
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(width, height, "Red triangle", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window.");
		getchar();
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	//specify the size of the rendering window
	glViewport(0, 0, width, height);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

	float vertices[] = {
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};

	glm::vec3 positions[] = {
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.2f, 0.5f, -0.15f),
		glm::vec3(-0.15f, -0.22f, -0.25f),
		glm::vec3(-0.38f, -0.2f, -0.123f),
		glm::vec3(0.24f, -0.4f, -0.35f),
		glm::vec3(-0.17f, 0.3f, -0.75f),
		glm::vec3(0.93f, -0.2f, -0.75f),
		glm::vec3(0.15f, 0.2f, -0.25f),
		glm::vec3(0.15f, 0.7f, -0.55f),
		glm::vec3(-0.13f, 0.1f, -0.15f)
	};

	glm::vec4 colors[] = {
		glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),   // Red
		glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),   // Green
		glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),   // Blue
		glm::vec4(1.0f, 1.0f, 0.0f, 1.0f),   // Yellow
		glm::vec4(1.0f, 0.0f, 1.0f, 1.0f),   // Purple
		glm::vec4(0.0f, 1.0f, 1.0f, 1.0f),   // Cyan
		glm::vec4(0.5f, 0.5f, 0.0f, 1.0f),   // Brown
		glm::vec4(0.0f, 0.5f, 0.5f, 1.0f),   // Teal
		glm::vec4(0.5f, 0.0f, 0.5f, 1.0f),   // Magenta
		glm::vec4(0.2f, 0.2f, 0.2f, 1.0f)    // Gray
	};

	unsigned int indices[] = {  // note that we start from 0!
		0, 3, 1,  // first Triangle
		1, 3, 2,   // second Triangle
	};

	// A Vertex Array Object (VAO) is an object which contains one or more Vertex Buffer Objects and is designed to store the information for a complete rendered object. 
	GLuint vbo, vao, ibo;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	//bind VAO
	glBindVertexArray(vao);

	//bind VBO
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//bind IBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//set attribute pointers
	glVertexAttribPointer(
		0,                  // attribute 0, must match the layout in the shader.
		3,                  // size of each attribute
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		3 * sizeof(float),  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(0);

	//create matrices for transforms
	glm::mat4 trans(1.0f);
	//trans = glm::scale(trans, glm::vec3(sx, sy, sz));
	trans = glm::rotate(trans, 80.0f, glm::vec3(0.0, 0.0, 1.0));


	// Check if the window was closed
	while (!glfwWindowShouldClose(window))
	{
		trans = glm::rotate(trans, float(glfwGetTime()) * glm::radians(2.0f), glm::vec3(0.0, 0.0, 1.0));
		// Swap buffers
		glfwSwapBuffers(window);

		// Check for events
		glfwPollEvents();

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Use our shader
		glUseProgram(programID);

		for (int i = 0; i < 10; i++)
		{
			unsigned int colorLocation = glGetUniformLocation(programID, "objectColor");
			glUniform4fv(colorLocation, 1, glm::value_ptr(colors[i]));
			glm::mat4 trans(1.0f);

			trans = glm::translate(trans, positions[i]);
			trans = glm::scale(trans, glm::vec3(0.2f, 0.2f, 0.0f));
			trans = glm::rotate(trans, 6.0f * float(glfwGetTime()), glm::vec3(0.0, 0.0, 1.0));
			unsigned int transformLoc = glGetUniformLocation(programID, "transform");
			glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}

		// send variables to shader
		unsigned int transformLoc = glGetUniformLocation(programID, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

		//bind VAO
		glBindVertexArray(vao);

		//ex 2
		//define the green color
		glm::vec4 greenColor(0.0f, 0.7f, 0.0f, .0f);
		// Get the location of the 'objectColor' uniform variable
		unsigned int colorLocation = glGetUniformLocation(programID, "objectColor");
		// Set the value of the 'objectColor' uniform variable
		glUniform4fv(colorLocation, 1, glm::value_ptr(greenColor));

		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	// Cleanup
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
	glDeleteVertexArrays(1, &vao);
	glDeleteProgram(programID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}