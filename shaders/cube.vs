#version 450 core
layout (location = 0) in vec3 aPos;

uniform float offset;

void main()
{	
	vec4 pos = vec4(aPos.x + offset, -aPos.y, aPos.z + 0.1f, 1.0f);
	gl_Position = pos;
}