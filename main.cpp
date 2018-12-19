#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "transform.h"

int main(void)
{
	display display;
	display.initDisplay();

	mesh mesh;
	mesh.initVertexArray();

	shader shader;
	GLuint programID = shader.loadShaders(".\\res\\shaders\\simpleVertexShader.vert", ".\\res\\shaders\\simpleFragmentShader.frag");

	transform transform(programID);

	mesh.initVertexArrayBuffer();

	while(!display.shouldQuit())
	{
		display.clear();
		shader.bind(programID);
		mesh.draw();
		transform.transformation(transform);

		display.update();
	}
	return 0;
}