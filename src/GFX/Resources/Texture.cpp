#include "GFX/Resources/Texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb.h>
#include <stb/stb_image.h>
#include <iostream>

Texture::Texture()
{

}
Texture::~Texture()
{
	glDeleteTextures(1, &mID);
}

void Texture::LoadTexture(const char* filename)
{

	//stbi_set_flip_vertically_on_load(1);
	stbi_uc* mData = stbi_load(filename, &mWidth, &mHeight, &mComp, 4);
	if (mData == nullptr)
	{
		std::cout << "Could not load texture: " << filename << std::endl;
		stbi_image_free(mData);
		return;
	}

	glDeleteTextures(1, &mID);

	// Create texture
	glGenTextures(1, &mID);
	glBindTexture(GL_TEXTURE_2D, mID);
	// Give pixel data to opengl
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, mData);
	stbi_image_free(mData);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

GLuint Texture::GetID()
{
	return mID;
}

void Texture::CopyFromMat(cv::Mat image)
{
	if (image.empty())
	{
		std::cout << "Could not copy from empty image" << std::endl;
		return;
	}

	glDeleteTextures(1, &mID);

	// Create texture
	glGenTextures(1, &mID);
	glBindTexture(GL_TEXTURE_2D, mID);

	mWidth = image.cols;
	mHeight = image.rows;
	
	cv::cvtColor(image, image, cv::COLOR_BGR2RGBA);
	cv::flip(image, image, 0);
	// Give pixel data to opengl

	mWidth = image.cols;
	mHeight = image.rows;
	mComp = image.channels();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.cols, image.rows, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.ptr());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}