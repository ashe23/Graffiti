#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform vec3 ourColor;

void main()
{
   FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0);
}