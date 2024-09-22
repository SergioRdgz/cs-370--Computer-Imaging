

#pragma once
#include <SDL2/SDL.h>
#include "GFX/Resources/FrameBuffer.hpp"
#include "GFX/Resources/Quad.hpp"
#include "GFX/Resources/ShaderProgram.hpp"
#include <glm/mat4x4.hpp>
#include "GFX/Resources/Texture.hpp"

class gfx_system
{
public:
	static gfx_system& GetInstance();
    gfx_system() {}
    ~gfx_system();
    gfx_system(const gfx_system& other) = delete;


    void Initialize();
    void ShutDown();
    void Update();

    //render functions
    void Render(); 
    //resize function (scaling everything that needs to do so) 

    SDL_GLContext mContext = nullptr;


    Texture image1;

	Texture image2;

	Texture finalImage;

private:
       
        

    //quad model
    Quad mQuadModel;   
        //shaders for different effects
    ShaderProgram* mQuadToScreen = nullptr;
};