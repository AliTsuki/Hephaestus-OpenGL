#pragma once

class shader
{
public:
	shader();
	virtual ~shader();

	GLuint loadShaders(const char *vertex_file_path, const char *fragment_file_path);

	void bind(GLuint shaderProgramID);

private:
	// ID of shader program
	GLuint programID;

	GLuint vertexShaderID;

	GLuint fragmentShaderID;
};