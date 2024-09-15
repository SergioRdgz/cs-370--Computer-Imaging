#include "GFX/Window.hpp"
#include "GFX/gfx_system.hpp"
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
	auto& gfx_system = gfx_system::GetInstance();
	SDL_Event event;
	bool run = true;

	gfx_system.Initialize();
	while (run)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				run = false;
				break;
			case SDL_WINDOWEVENT:
				Window::WindowEvent(&event);
				break;

			default:
				break;
			}
		}

		//graphics things hereS
		gfx_system.Update();
		gfx_system.Render();
		//imgui things here

	}
	

	//destroy graphics
	gfx_system.ShutDown();
	Window::DestroyWindow();
    return 0;
}

