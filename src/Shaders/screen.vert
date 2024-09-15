#version 440 core

layout (location = 0) in vec2 vPosition;
layout (location = 1) in vec2 vUV;

out vec2 TexCoords;

void main()
{
    TexCoords = vUV;
    gl_Position = vec4(vPosition.x, vPosition.y, 0.0, 1.0); 
}  