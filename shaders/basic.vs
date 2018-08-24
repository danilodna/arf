#version 330 core
layout (location = 0) in vec4 vertex;

out vec2 aTexCoord;
out vec4 color;

uniform mat4 model;
uniform mat4 projection;
uniform vec3 objectColor;

void main()
{
	aTexCoord = vertex.zw;
	gl_Position = projection * model * vec4(vertex.xy, 0.0f, 1.0f);
	color = vec4(objectColor, 1.0f);
}
