#version 330 core
layout (location = 0) in vec4 vertex;
layout (location = 1) in vec4 color;

out vec4 ourColor;

vec4 correctPosition;

uniform mat4 projection;

void main()
{
	correctPosition = vec4(vertex.xy, 0.0f, 1.0f);
	gl_Position = projection * correctPosition;
	ourColor = vec4(0.0, 0.0, 1.0, 1.0);
}
