#version 440 core

out vec4 FragColor;

in vec2 TexCoords;

layout(location = 4) uniform sampler2D texture0;
layout(location = 5) uniform bool hasTexture;

vec4 ChooseColor()
{
    if(hasTexture)
    {
        return texture(texture0, TexCoords).rgba;
    }
    else
        return vec4(0.5f,0.5f,0.5f,1.0f);
}
void main()
{
    FragColor = ChooseColor();
} 