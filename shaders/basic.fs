#version 330 core

out vec4 FragColor;
in vec4 color;

in vec2 aTexCoord;

void main()
{
	FragColor = color;
}
