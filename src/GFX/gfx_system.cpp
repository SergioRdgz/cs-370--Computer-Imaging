#include "GFX/gfx_system.hpp"
#include "GFX/Window.hpp"
#include <GL/glew.h>
#include <iostream>
//#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace {
	void checkGLError() {
		GLenum err;
		while ((err = glGetError()) != GL_NO_ERROR) {
			std::cerr << "OpenGL error: 0x" << std::hex << err << std::endl;
		}
	}

	void GLAPIENTRY
		MessageCallback(GLenum source,
			GLenum type,
			GLuint id,
			GLenum severity,
			GLsizei length,
			const GLchar* message,
			const void* userParam)
	{
		fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
			(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
			type, severity, message);
	}


}

gfx_system& gfx_system::GetInstance()
{
	static gfx_system instance;
	return instance;
}

gfx_system::~gfx_system()
{

}

void gfx_system::Initialize()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_Window* window = Window::GetWindow();

	mContext = SDL_GL_CreateContext(window);
	if (mContext == nullptr)
	{
		SDL_DestroyWindow(window);
		std::cout << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}

	if (glewInit() != GLEW_OK)
	{
		SDL_GL_DeleteContext(mContext);
		SDL_DestroyWindow(window);
		std::cout << "GLEW Error: Failed to init" << std::endl;
		SDL_Quit();
		exit(1);
	}

	//now that OpenGL is initialized create the what nots needed
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(MessageCallback, 0);

	//initialize shaders
	mQuadToScreen = ShaderProgram::CreateShaderProgram("src\\shaders\\screen.vert", "src\\shaders\\screen.frag");
	mImageQuad = ShaderProgram::CreateShaderProgram("src\\shaders\\quad.vert", "src\\shaders\\quad.frag");
	
	//initialize frame buffers
	mFinalBuffer.Create();
	mProcessedBuffer.Create();

	//initialize whatever else needs to do so
	mQuadModel.Initialize();

	Mtx1 =glm::translate(glm::mat4(1.0f),glm::vec3(-0.5f,0.5f,0.0f))* glm::scale(glm::mat4(1.0f),glm::vec3(0.40f,0.40f,1.0f)); 
	Mtx2 =glm::translate(glm::mat4(1.0f),glm::vec3(0.5f,0.5f,0.0f))* glm::scale(glm::mat4(1.0f),glm::vec3(0.40f,0.40f,1.0f)); 
	Mtx3 =glm::translate(glm::mat4(1.0f),glm::vec3(0.0f,-0.5f,0.0f))* glm::scale(glm::mat4(1.0f),glm::vec3(0.40f,0.40f,1.0f)); 
	
}

void gfx_system::ShutDown()
{
	mQuadModel.Destroy();

	mFinalBuffer.Delete();

	delete mQuadToScreen;
}

void gfx_system::Update()
{

}

void gfx_system::Render(bool loaded1, bool loaded2, char ShowImages)
{
	/*int width, height;
	Window::GetWindowWidthHeight(&width, &height);

	glViewport(0, 0, width, height);
	mFinalBuffer.Bind();

	glClearColor(0.2f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	RenderImages();*/
	
	
	//render the whatever the final buffer has into the screen
	RenderFinalBufferToScreen();
}

void gfx_system::RenderFinalBufferToScreen()
{
	int width, height;
	Window::GetWindowWidthHeight(&width, &height);
	glViewport(0, 0, width, height);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	mQuadToScreen->Use();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, finalImage.GetID());
	mQuadModel.Render();

	
}

void gfx_system::RenderImages()
{
	//draw image 1
	mImageQuad->Use();
	mImageQuad->SetUniform(0, Mtx1);
	mImageQuad->SetUniform("hasTexture", false);
	//set the texture
	mQuadModel.Render();

	//draw image 2
	mImageQuad->SetUniform(0, Mtx2);
	mImageQuad->SetUniform("hasTexture", false);
	//set the texture
	mQuadModel.Render();
}

void gfx_system::RenderThird()
{
	mProcessedBuffer.Bind();
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	mQuadToScreen->Use();

	mQuadModel.Render();


	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}