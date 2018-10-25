#version 330 core
layout (location = 0) in vec4 vertex;
layout (location = 1) in vec4 color;

out vec4 ourColor;

uniform mat4 projection;
uniform mat4 model;

void main()
{
	gl_Position = projection * model * vertex;
	ourColor = color;
}
