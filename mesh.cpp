#include <iostream>

#include <GL\glew.h>

#include "mesh.h"

// Constructor for mesh
mesh::mesh()
{

}

// Destructor for mesh
mesh::~mesh()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
}

void mesh::initVertexArray()
{
	// Create a vertex array
	GLuint vertexArrayID;
	// VERTEX ARRAY
	// Generate a vertex array at address of VertexArrayID
	glGenVertexArrays(1, &vertexArrayID);
	// Bind the vertex array VertexArrayID
	glBindVertexArray(vertexArrayID);
}

void mesh::initVertexArrayBuffer()
{
	// An array of 3 vectors which represents 3 vertices
	static const GLfloat g_vertex_buffer_data[] =
	{
	   -1.0f, -1.0f, 0.0f,
	   1.0f, -1.0f, 0.0f,
	   0.0f,  1.0f, 0.0f,
	};

	// This will identify our vertex buffer
	GLuint vertexBuffer;

	// VERTEX ARRAY BUFFER
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexBuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

// Draw the mesh
void mesh::draw()
{
	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

	glDisableVertexAttribArray(0);
}