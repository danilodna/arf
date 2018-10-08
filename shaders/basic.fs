#version 330 core

out vec4 FragColor;
in vec4 color;

in vec2 aTexCoord;

uniform sampler2D ourTexture;

void main()
{
	FragColor = color;
	// FragColor = texture(ourTexture, aTexCoord);
}
