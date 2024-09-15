#include "GFX/Resources/FrameBuffer.hpp"

void FrameBuffer::Bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, mFbo);
}

void FrameBuffer::Create()
{
	glGenFramebuffers(1, &mFbo);
}

void FrameBuffer::Delete()
{
	glDeleteFramebuffers(1, &mFbo);
}