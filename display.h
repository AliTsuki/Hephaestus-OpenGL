#pragma once

class display
{
public:
	display();
	virtual ~display();

	void initDisplay();

	bool shouldQuit();

	void clear();

	void update();

private:
	GLFWwindow* window;

	bool quit;
};