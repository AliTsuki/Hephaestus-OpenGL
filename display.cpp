#include <iostream>
#include <string>

#include <GL\glew.h>
#include <GLFW/glfw3.h>
#include <SDL2\SDL.h>

#include "display.h"

// Constructor for display
display::display()
{	

}

// Destructor for display
display::~display()
{
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}

void display::initDisplay()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "Tutorial 02 - Red triangle", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
}

// Check if quit is true, used by main loop
bool display::shouldQuit()
{
	// Check if the ESC key was pressed or the window was closed
	quit = glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window);
	return quit;
}

// Clears the display
void display::clear()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT);
}

// Updates the display, swaps buffer, checks if SDL is set to quit
void display::update()
{
	// Swap buffers
	glfwSwapBuffers(window);
	glfwPollEvents();
}