// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Include GLEW
#include "Dependencies/GLEW/glew.h"

// Include GLFW
#include "Dependencies/GLFW/glfw3.h"

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
	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f,
	};

	// To-DO: Ex 2
	// Add indices for EBO

	// To-DO: Ex 3
	// Add a VAO
	// !!! VAO must be bound BEFORE the VBO & EBO

	// Create a vertex buffer object
	GLuint VBO_ID;
	glGenBuffers(1, &VBO_ID);
	// Bind buffer to a target
	glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
	// Upload data to the buffer
	//https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBufferData.xhtml
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(vertices),
		&vertices[0], //pointer to the data
		//vertices
		GL_STATIC_DRAW);

	// To-DO: Ex 2
	// Create EBO, Bind it, upload data

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
		glVertexAttribPointer(
			0,                  // attribute 0, must match the layout location in the shader.
			3,                  // size of each attribute
			GL_FLOAT,           // type of data
			GL_FALSE,           // should be normalized?
			3 * sizeof(GL_FLOAT),   // stride
			0            // array buffer offset
			//same as (void*)0 for older OpenGL versions
		);

		// Draw a triangle
		// Ex2: How do we change it to use indices?
		glDrawArrays(GL_TRIANGLES, 0, 3);
		// type of primitive
		// starting index
		// nr of vertices
		// 3 consecutive indices starting at
		// 0 -> 1 triangle
	}

	// Cleanup VBO
	// TO-DO: Ex 2 & 3
	// De-allocate memory from all buffers
	glDeleteBuffers(1, &VBO_ID);
	glDeleteProgram(programID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}


