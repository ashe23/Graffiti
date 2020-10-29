#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/detail/type_mat.hpp>

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
	void SetMat4(const std::string& Name, glm::mat4 Value) const;
};    