#include "GFX/Resources/Quad.hpp"

namespace Meshes
{
	//temporal thing, just want to get this working
	float vertices[] = {
		0.0f, 0.0f,0.0f,0.0f,
		1.0f, 0.0f,1.0f,1.0f,
		0.0f,1.0f,0.0f,1.0f
	};
}
void Quad::Destroy()
{
	glDeleteBuffers(1, &mVbo);
	glDeleteVertexArrays(1, &mVao);
}

void Quad::Initialize()
{
	glGenVertexArrays(1, &mVao);
	glGenBuffers(1, &mVbo);

	// Create positions buffer
	glBindVertexArray(mVao);
	glBindBuffer(GL_ARRAY_BUFFER, mVbo);
	glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizei>(sizeof(float)*4*12), Meshes::vertices, GL_STATIC_DRAW);

	// Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*4, nullptr);
	// UVs
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float)*4, reinterpret_cast<void*>(sizeof(float)*2));


	glBindVertexArray(0);
}

void Quad::Render()
{
	// Bind and draw vertices
	glBindVertexArray(mVao);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glDrawArrays(GL_TRIANGLES, 0, (unsigned)3);
}