#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

// model view projection ! order matters (projection * view * model)
uniform mat4 pvm;

void main()
{
	gl_Position = pvm * vec4(aPos, 1.0f);
	TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}