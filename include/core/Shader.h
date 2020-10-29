#pragma once
#include <string>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


enum class ShaderType
{
	VERTEX,
	FRAGMENT
};


// Shader class responsible for
// reading vertex or fragment shader contents
// compiling and creating shader object in glfw context
class Shader
{
public:
	Shader(ShaderType Type, const char* Path);
	bool IsValid() const;
	// Returns Shader Object ID
	GLuint GetID() const;
private:
	ShaderType Type;
	std::string ShaderFilePath;
	GLuint ShaderObjectID;
	bool bIsValid;
private:
	void Init();
	std::string ReadShaderCodeFromFile();
	void CheckCompileError();
};