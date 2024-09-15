//#include "GFX/gfx_system.hpp"
//
//#include <iostream>
//gfx_system& gfx_system::GetInstance()
//{
//	static gfx_system instance;
//	return instance;
//}
//
//gfx_system::~gfx_system()
//{
//
//}
//
//void gfx_system::Initialize()
//{
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
//	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
//
//	SDL_Window* window = Window::GetWindow();
//
//	mContext = SDL_GL_CreateContext(window);
//	if (mContext == nullptr)
//	{
//		SDL_DestroyWindow(window);
//		std::cout << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
//		SDL_Quit();
//		exit(1);
//	}
//
//	if (glewInit() != GLEW_OK)
//	{
//		SDL_GL_DeleteContext(mContext);
//		SDL_DestroyWindow(window);
//		std::cout << "GLEW Error: Failed to init" << std::endl;
//		SDL_Quit();
//		exit(1);
//	}
//
//	//now that OpenGL is initialized create the what nots needed
//
//	//initialize shaders
//	
//	//initialize frame buffers
//	//mFinalBuffer.Create();
//	//initialize whatever else needs to do so
//	//mQuadModel.Initialize();
//}
//
//void gfx_system::ShutDown()
//{
//	//mQuadModel.Destroy();
//
//	//mFinalBuffer.Delete();
//
//}
//
//void gfx_system::Update()
//{
//
//}
//
//void gfx_system::Render()
//{
//	//mFinalBuffer.Bind();
//	
//	/*glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT );
//
//
//
//	SDL_GL_SwapWindow(Window::GetWindow());*/
//}