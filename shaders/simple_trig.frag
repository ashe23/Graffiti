#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
uniform sampler2D ourTexture3;

uniform vec3 ourColor;

void main()
{
   FragColor = mix( mix(texture(ourTexture1, TexCoord),texture(ourTexture2, TexCoord), 0.5) , texture(ourTexture3,TexCoord) , 0.4);
}