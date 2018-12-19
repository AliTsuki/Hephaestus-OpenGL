#pragma once

class mesh
{
public:
	mesh();
	virtual ~mesh();

	void initVertexArray();

	void initVertexArrayBuffer();

	void draw();

private:
	// Create a vertex array
	GLuint vertexArrayID;
	// This will identify our vertex buffer
	GLuint vertexBuffer;
};