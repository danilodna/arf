#version 330 core
layout (location = 0) in vec4 vertex;

out vec2 aTexCoord;
out vec4 color;

uniform mat4 model;
uniform mat4 projection;
uniform vec3 objectColor;

// Texture Coordinates
// 0.0f, 0.0f,  // lower-left corner  
// 1.0f, 0.0f,  // lower-right corner
// 0.5f, 1.0f   // top-center corner

void main()
{
	aTexCoord = (-vertex.xy);
	// gl_Position = projection * model * vec4(vertex.xy, 0.0f, 1.0f);
	gl_Position = vec4(vertex.xy, 0.0f, 1.0f);
	color = vec4(vec3(0.0f, 1.0f, 0.0f), 1.0f);
}
