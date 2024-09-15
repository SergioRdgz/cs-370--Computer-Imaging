#include "Window.hpp"

#include <iostream>

namespace  Window
{

	bool InitializeWindow(int width, int height, std::string WindowName)
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			std::cout << "could not initialize sdl" << SDL_GetError() << std::endl;
			return false;
		}
		std::string window_name = WindowName.empty() ? "Chaos For Sale" : WindowName;

		window = SDL_CreateWindow(window_name.c_str(), 100, 100, width, height, SDL_WINDOW_OPENGL);


		if (window == nullptr)
		{
			std::cout << "sdl_create window error" << SDL_GetError() << std::endl;
			SDL_Quit();
			return false;
		}
		//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
		//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 32);

		// Be able to resize the window
		SDL_SetWindowResizable(window, SDL_FALSE);

		return true;
	}

	void DestroyWindow()
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	SDL_Window* GetWindow()
	{
		return window;
	}
	void ResizeWindow(int width, int height)
	{
		SDL_SetWindowSize(window, width, height);
		//glViewport(0, 0, width, height);
		//GFX_SYS.ResizeBuffers();
	}

	void WindowEvent(const SDL_Event* event)
	{
		//very limited uses check https://wiki.libsdl.org/SDL2/SDL_WindowEvent for any event we want and dont find 
		if (event->window.event == SDL_WINDOWEVENT_RESIZED)
		{
			//PUE::GFX::Window::ResizeWindow(event->window.data1, event->window.data2);
		
		}
	}

	void GetWindowWidthHeight(int* width, int* height)
	{
		SDL_GetWindowSize(window, width, height);

	}

	void SetFullscreen()
	{
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
}