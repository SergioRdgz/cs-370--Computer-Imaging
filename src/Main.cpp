#include "GFX/Window.hpp"
#include <iostream>
#ifdef _WIN32
#undef main
#endif

int main(void)
{  
	bool success = Window::InitializeWindow(1280, 720 , " CS-370 Image Processing : Sergio Rodriguez");

	if (!success)
	{
		std::cout << " something went wrong when initializing the window >:(" << std::endl;

		Window::DestroyWindow();
		return 0;
	}

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{

		switch (event.type)
		{
		case SDL_QUIT:
			break;
		case SDL_WINDOWEVENT:
			Window::WindowEvent(&event);
			break;
		
		default:
			break;
		}

		//graphics things hereS

		//imgui things here

	}

	//destroy graphics
	Window::DestroyWindow();
    return 0;
}

