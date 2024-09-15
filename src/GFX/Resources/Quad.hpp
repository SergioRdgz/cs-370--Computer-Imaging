#pragma once
#include <GL/glew.h>

class Quad
{
public:
	void Initialize();
	void Destroy();

	void Render();
private:
	GLuint mVao = -1;
	GLuint mVbo = -1;
};