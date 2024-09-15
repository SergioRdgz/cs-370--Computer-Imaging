#pragma once
#include <GL/glew.h>


class FrameBuffer
{
public:
	void Create();
	void Delete();
	void Bind();
private:
	GLuint mFbo;
	GLuint mTexHandle;
	GLuint mRbo;
};