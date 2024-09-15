#include <SDL2/SDL.h>

#include <string>
#pragma once
namespace  Window
{

	static SDL_Window* window = nullptr;

	/**
	* Initialize SDL and create a window
	* @param width and height: the starting values of the opened window
	* @return bool: whether everything went well or not
	*/
	bool InitializeWindow(int width, int height, std::string WondowName = "");

	/**
	* Destroy the window and also quit SDL
	*/
	void DestroyWindow();

	/**
	* Get the window pointer since accessing from outside of the scope directly will return a null pointer
	*/
	SDL_Window* GetWindow();

	/**
	* Resize the window to a given size
	* @param width and height: the values to resize the window
	*/
	void ResizeWindow(int width, int height);

	/**
	* Call this function whenever a sdl event regarding the window comes
	* @param event: the event we have to deal with
	*/
	void WindowEvent(const SDL_Event* event);

	/**
	* Call this function whenever a sdl event regarding the window comes
	* @param event: the event we have to deal with
	*/
	void GetWindowWidthHeight(int* width, int* height);

	//Self explanatory
	void SetFullscreen();

}