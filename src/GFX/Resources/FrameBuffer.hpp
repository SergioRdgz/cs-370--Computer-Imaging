#pragma once
#include <GL/glew.h>


class FrameBuffer
{
public:
	void Create();
	void Delete();
	void Bind();
	GLuint mTexHandle;
private:
	GLuint mFbo;
	GLuint mRbo;
};