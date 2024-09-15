#version 440 core

out vec4 FragColor;

in vec2 TexCoords;

layout(location = 4) uniform sampler2D texture0;

void main()
{
    vec3 col = texture(texture0, TexCoords).rgb;
    FragColor = vec4(col, 1.0);
} 