#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl2.h"
#include "imgui/imgui_impl_opengl3.h"

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


	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplSDL2_InitForOpenGL(Window::GetWindow(), &gfx_system.mContext);
	ImGui_ImplOpenGL3_Init("#version 330");

	
	while (run)
	{
		
		while (SDL_PollEvent(&event))
		{
			ImGui_ImplSDL2_ProcessEvent(&event);//without this we cant resize or use imgui at all
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

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();

		//graphics things hereS
		gfx_system.Update();
		gfx_system.Render();
		//imgui things here
		ImGui::Begin(" testing testing imgui ");
		ImGui::Text(" does this really work? ");
		bool test;
		ImGui::Checkbox("just for test", &test);
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		SDL_GL_SwapWindow(Window::GetWindow());
	}
	
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
	//destroy graphics
	gfx_system.ShutDown();
	Window::DestroyWindow();
    return 0;
}

