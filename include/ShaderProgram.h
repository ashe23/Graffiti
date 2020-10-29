#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader;

// ShaderProgram class responsible for
// creating program objectin glfw context
// attaching different ShaderObjects(Shader class) to program
class ShaderProgram
{
	GLuint ProgramID;
	bool bIsValid;
public:
	ShaderProgram();
	~ShaderProgram();
	void Use();
	void Link();
	void Attach(const Shader& ShaderObj) const;
	void Detach(const Shader& ShaderObj) const;
	bool IsValid() const;
	void SetBool(const std::string& Name, bool Value) const;
	void SetInt(const std::string& Name, int Value) const;
	void SetFloat(const std::string& Name, float Value) const;
};