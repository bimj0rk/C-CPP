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

//include glut
#include "dependente\freeglut\freeglut.h"

#include "shader.hpp"

//variables
GLFWwindow* window;
const int width = 1024, height = 768;
float x = 0.0, y = 0.25, z = 0.0;

//window callback
void window_callback(GLFWwindow* window, int new_width, int new_height)
{
	glViewport(0, 0, new_width, new_height);
}

//render function
void render_text(const float x, const float y, const std::string& text)
{	
	glRasterPos2f(x, y);
	for (const char& c : text) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
}

//render the press to interact text
void render_press()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	render_text(-0.7f, 0.0f, "Press E to interact");
}

//render the dialogue
void render_dialogue() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	render_text(-1.0f, -0.9f, "Greetings, Agent Tanner. I've been waiting for you...");
}

//init glut
void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}


int main(int argc, char**argv)
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(width, height, "DEFCON - Apocalypse: A 2D Demo", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window.");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		glfwTerminate();
		return -1;
	}

	//init glu
	glutInit(&argc, argv);
	init();

	//specify the size of the rendering window
	glViewport(0, 0, width, height);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Create and compile our GLSL program from the shaders
	// More about this in the following labs
	GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

	float vertices[] = {
		0.0, 0.0, 0.1,
		0.1, 0.0, 0.1,
		0.0, 0.1, 0.1,
		0.1, 0.1, 0.1,
	};


	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 2, //
		1, 3, 2,
	};

	glm::vec3 positions[] = {
		glm::vec3(x, y, z),
		glm::vec3(0.5f,  0.5f,  0.0f),
	};

	// A Vertex Array Object (VAO) is an object which contains one or more Vertex Buffer Objects and is designed to store 
	// the information for a complete rendered object.
	GLuint vbo, vao, ibo;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//set attribute pointers
	glVertexAttribPointer(
		0,                  // attribute 0, must match the layout in the shader.
		3,                  // size of each attribute
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		3 * sizeof(float),                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(0);
	
	glfwSetFramebufferSizeCallback(window, window_callback);

	// Check if the window was closed
	while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		// Swap buffers
		glfwSwapBuffers(window);

		// Check for events
		glfwPollEvents();

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Use our shader
		glUseProgram(programID);
		
		//add view and projection matrices

		if (glfwGetKey(window, GLFW_KEY_D)) {
			if (x < 0.95f) x += 0.01f;
		}

		if (glfwGetKey(window, GLFW_KEY_A)) {
			if (x > -0.95f) x -= 0.01f;
		}

		if (glfwGetKey(window, GLFW_KEY_W)) {
			if (y < 0.95f) y += 0.01f;
		}

		if (glfwGetKey(window, GLFW_KEY_S)) {
			if (y > -0.95f) y -= 0.01f;
		}
		
		glm::mat4 player;
		player = glm::translate(player, glm::vec3(x, y, z));

		unsigned int transformLoc = glGetUniformLocation(programID, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(player));

		unsigned int transformLoc2 = glGetUniformLocation(programID, "color");
		glUniform4fv(transformLoc2, 1, glm::value_ptr(glm::vec4(0.5f/ 10.0f, 255, 0.5f, 1.0)));

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		for (int i = 1; i < 2; ++i) {
			glm::mat4 obstacle;
			obstacle = glm::translate(obstacle, positions[i]);

			unsigned int transformLoc = glGetUniformLocation(programID, "transform");
			glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(obstacle));

			unsigned int transformLoc2 = glGetUniformLocation(programID, "color");
			glUniform4fv(transformLoc2, 1, glm::value_ptr(glm::vec4(255, 255, 0.5f, 1.0)));

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}

		if (x >= 0.4f && x <= 0.6f && y >= 0.4f && y <= 0.6f)
		{
			render_press();
			if (glfwGetKey(window, GLFW_KEY_E)) {
				render_dialogue();
			}
		}

		//bind VAO
		glBindVertexArray(vao);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	// Cleanup VBO
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
	glDeleteProgram(programID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}