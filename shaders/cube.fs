#version 450 core
out vec4 FragColor;

in vec2 TexCoords;


uniform sampler2D CubeTexture;

void main()
{
	FragColor = texture(CubeTexture, TexCoords);
}