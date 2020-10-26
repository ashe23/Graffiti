#pragma once

#include "Util.h"

enum class ShaderType
{
	VERTEX,
	FRAGMENT
};

enum class ShaderCompilationType
{
	Shader,
	Program
};

// Shader class responsible for
// reading vertex and fragment shader contents
// compiling and linking to program
class Shader
{
public:
	Shader(const char* VertexShaderPath, const char* FragmentShaderPath);
	~Shader();
	void Use();
	void SetBool(const std::string& Name, bool Value) const;
	void SetInt(const std::string& Name, int Value) const;
	void SetFloat(const std::string& Name, float Value) const;
private:
	unsigned int ID;
	const char* VertexShaderPath;
	const char* FragmentShaderPath;
	GLuint VertexShader;
	GLuint FragmentShader;
private:
	void CheckCompileError(unsigned int Shader, ShaderCompilationType Type);
	void Compile();
};