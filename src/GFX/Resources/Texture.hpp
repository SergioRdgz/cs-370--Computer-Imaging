#pragma once
#include <GL/glew.h>
#include <opencv2/opencv.hpp>

class Texture
{
public:

	Texture();
	~Texture();

	void CopyFromMat(cv::Mat& image);
	void LoadTexture(const char* filename);
	
	GLuint GetID();
private:
	GLuint mID = -1;
	int mWidth = 0;
	int mHeight = 0;
	int mComp = 0;
};