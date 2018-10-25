#version 330 core
layout (location = 0) in vec4 vertex;
layout (location = 1) in vec4 texCoords;

out vec2 aTexCoord;

uniform mat4 model;
uniform mat4 projection;

void main()
{
	gl_Position = projection * model * vertex;
	aTexCoord = texCoords.xy;
}
