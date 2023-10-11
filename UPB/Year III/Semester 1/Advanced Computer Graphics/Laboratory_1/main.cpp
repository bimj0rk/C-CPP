// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Include GLFW
#include "dependente/glfw/glfw3.h"

//variables
GLFWwindow* window;
const int width = 1024, height = 768;

int main()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(width, height, "Our first test :)", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window.");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	//specify the size of the rendering window
	#define GL_SILENCE_DEPRECATION
	float i = 0.0f;
	float j = 0.0f;

	// Check if the window was closed
	while (!glfwWindowShouldClose(window))
	{
		// Check for events
		glfwPollEvents();

		// Swap buffers
		glfwSwapBuffers(window);

		//if (i > 1.0f)
		//{
		//	i = 0.0f;
		//}

		//if (j > 1.0f)
		//{
		//	j = 0.0f;
		//}

		//glClearColor(i += 0.1f, 0.0f, j += 0.05f, 0.0f);

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);
	} 

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}