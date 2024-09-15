#include "GFX/Resources/FrameBuffer.hpp"
#include "GFX/Window.hpp"
#include <iostream>


void FrameBuffer::Bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, mFbo);
	
}

void FrameBuffer::Create()
{
	glGenFramebuffers(1, &mFbo);

	int width, height;
	Window::GetWindowWidthHeight(&width, &height);

	glGenTextures(1, &mTexHandle);
	glGenRenderbuffers(1, &mRbo);
	glBindFramebuffer(GL_FRAMEBUFFER, mFbo);
	
	glBindRenderbuffer(GL_RENDERBUFFER, mRbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, mRbo);


	glBindTexture(GL_TEXTURE_2D, mTexHandle);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, GL_NONE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mTexHandle, 0);


	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
}

void FrameBuffer::Delete()
{
	glDeleteFramebuffers(1, &mFbo);
	glDeleteTextures(1, &mTexHandle);
	glDeleteRenderbuffers(1, &mRbo);
}