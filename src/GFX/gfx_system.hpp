

#pragma once
#include <SDL2/SDL.h>
#include "GFX/Resources/FrameBuffer.hpp"
#include "GFX/Resources/Quad.hpp"
#include "GFX/Resources/ShaderProgram.hpp"


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
    void Render(); //just for testing render
    void RenderFinalBufferToScreen();

    //resize function (scaling everything that needs to do so) 

private:
    SDL_GLContext mContext = nullptr;

    //quad model
    Quad mQuadModel;
    //saved data 
        // image 1
        // image 1s matrix
        //
        // image 2
        // image 2s matrix
        
        // Final frame buffer
    FrameBuffer mFinalBuffer;
        // processed frame buffer (image 1 (whatever operation) image 2)
        
        // processed images matrix
        //shaders for different effects
    ShaderProgram* mQuadToScreen = nullptr;
};