#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl2.h"
#include "imgui/imgui_impl_opengl3.h"

#include "GFX/Window.hpp"
#include "GFX/gfx_system.hpp"
#include <iostream>

#include "opencv2/opencv.hpp"

#ifdef _WIN32
#undef main
#endif
#include <filesystem>

namespace fs = std::filesystem;

// Function to list files in a directory
std::vector<std::string> ListFiles(const std::string& path) {
	std::vector<std::string> files;

	// Iterate through directory entries and store file names
	for (const auto& entry : fs::directory_iterator(path)) {
		if (entry.is_regular_file()) {
			files.push_back(entry.path().string());
		}
	}

	return files;
}

//This function will only take care of the selection as the name says
//no image will be loaded here
void SelectImage(const char* path, const char* tittle ,cv::String& selected)
{
	if (ImGui::BeginCombo(tittle, selected.c_str()))
	{
		cv::String newSelection = selected;
		auto files = ListFiles(path);
		
		//skip the first one since it will be .DS_Store
		for (unsigned int i = 1; i < files.size(); i++) 
		{
			const auto& file = files[i];			

			if (ImGui::Selectable(file.c_str()))
			{			
				newSelection = file;
			}
		}
		ImGui::EndCombo();

		//if the new selected and the old one are the same then we dont need to do anything
		if ( selected.size() == newSelection.size() && strncmp(selected.c_str(), newSelection.c_str(), selected.size()) == 0)
			return;

		//in the oposite case just save the new thing
		selected = newSelection;
		
	}
}

int main(void)
{
	bool success = Window::InitializeWindow(1280, 720, " CS-370 Image Processing : Sergio Rodriguez");

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

	cv::String selected1 = "";

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
		//ImGui::Text(" does this really work? ");
		//bool test;
		//ImGui::Checkbox("just for test", &test);

		////do a file explorer with imgui to get in a string the image to open
		//
		SelectImage("images", "Image 1", selected1);

		
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

