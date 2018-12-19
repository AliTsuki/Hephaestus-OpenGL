#pragma once

class transform
{
public:
	transform(GLuint programID);
	virtual ~transform();

	void transformation(transform);

private:
	GLuint matrixID;

	glm::mat4 Projection;

	glm::mat4 View;

	glm::mat4 Model;

	glm::mat4 MVP;
};