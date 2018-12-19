#include <iostream>
#include <SDL2/SDL.h>

#include "input.h"

// constructor for input
input::input()
{
	SDL_Event event;
}

// reads event and does stuff, is broken needs fix
void input::readInput(SDL_Event event)
{
	SDL_PollEvent(&event); // poll checks constantly

	switch (event.type)
	{
		// case for keypresses
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
			std::cout << "W was pressed!" << std::endl;
			break;
		case SDLK_a:
			std::cout << "A was pressed!" << std::endl;
			break;
		case SDLK_s:
			std::cout << "S was pressed!" << std::endl;
			break;
		case SDLK_d:
			std::cout << "D was pressed!" << std::endl;
			break;
		case SDLK_ESCAPE:
			SDL_Quit();
			break;
		}
		break;

		//case for mouse button presses
	case SDL_MOUSEBUTTONDOWN:
		switch (event.button.button)
		{
		case SDL_BUTTON_LEFT:
			std::cout << "Left Mouse Button was pressed!" << std::endl;
			break;
		case SDL_BUTTON_RIGHT:
			std::cout << "Right Mouse Button was pressed!" << std::endl;
			break;
		default:
			std::cout << "Another Mouse Button was pressed!" << std::endl;
			break;
		}
		break;

		//case for mouse motion
	case SDL_MOUSEMOTION:
		int mouseX = event.motion.x;
		int mouseY = event.motion.y;
		std::cout << "mouseX: " << mouseX << ", mouseY: " << mouseY << std::endl;
		break;
	}
}