#pragma once
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


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
	unsigned int GetID() const;
	void SetBool(const std::string& Name, bool Value) const;
	void SetInt(const std::string& Name, int Value) const;
	void SetFloat(const std::string& Name, float Value) const;
	void SetMatrix4(const std::string& Name, glm::mat4 Value) const;
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