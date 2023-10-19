// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Include GLEW
#include "dependente\glew\glew.h"

// Include GLFW
#include "dependente\glfw\glfw3.h"

#include "shader.hpp"

//variables
GLFWwindow* window;
const int width = 728, height = 728;

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

	// Initialize GLEW (OpenGL Extension Wrangler Library)
	// = a loader library :)
	// OpenGl libraries are contained in binary form (.dll)
	// inside your graphics drivers,
	// and GLEW is a portal between us and the OpenGL
	// that already lives in our computers
	glewExperimental = true;
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

	// Create and compile our GLSL program from the shaders
	// More about this in the following lab
	GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

	glUseProgram(programID);

	// Create some data for the vertices
	
	// Add a VAO
	// !!! VAO must be bound BEFORE the VBO & EBO
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	
	//VBO
	/*GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
	};
	*/

	//IBO
	GLfloat vertices[] = {
		0.5f, 0.5f, 0.0f, //TR
		0.5f, -0.5f, 0.0f, //BR
		-0.5f, -0.5f, 0.0f, //BL
		-0.5f, 0.5f, 0.0f, //TL
		//for ex 4
		-0.2f, 0.0f, 0.0f,
		0.2f, 0.0f, 0.0f,
		0.0f, 0.2f, 0.0f,
		-0.2f, -0.4f, 0.0f,
		0.2f, -0.4f, 0.0f,
		0.0f, -0.6f, 0.0f,
	};

	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3,
		4, 5, 6,
		7, 8, 9.
	};

	// Create a vertex buffer object
	GLuint VBO_ID;//VBO
	glGenBuffers(1, &VBO_ID);//VBO
	 
	GLuint IBO_ID;//IBO
	glGenBuffers(1, &IBO_ID);//IBO
	
	// Bind buffer to a target
	glBindVertexArray(VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);//VBO

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO_ID);//IBO


	// Upload data to the buffer
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) ,&vertices[0], GL_STATIC_DRAW); //VBO

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);//IBO

	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //solid mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode

	// Check if the window was closed
	while (!glfwWindowShouldClose(window))
	{
		// Swap buffers
		glfwSwapBuffers(window);

		// Check for events
		glfwPollEvents();

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Use our shader
		//glUseProgram(programID);

		//enable vertex attribute
		//for now we have just the position
		//things will change with colors, normals etc.
		glEnableVertexAttribArray(0);

		// attribute buffer : vertices
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), 0);

		// Draw a triangle
		glDrawArrays(GL_TRIANGLES, 0, 3); //VBO
		glDrawElements(GL_TRIANGLES, 15, GL_UNSIGNED_INT, 0);//IBO
		// type of primitive
		// starting index
		// nr of vertices
		// 3 consecutive indices starting at
		// 0 -> 1 triangle
	}
		
	// Cleanup VBO
	glDeleteBuffers(1, &VBO_ID);
	glDeleteBuffers(1, &IBO_ID);
	glDeleteProgram(programID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}