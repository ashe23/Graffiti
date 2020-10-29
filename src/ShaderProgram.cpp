#include "ShaderProgram.h"
#include "Shader.h"

#include "spdlog/spdlog.h"

ShaderProgram::ShaderProgram()
{
	ProgramID = glCreateProgram();
	bIsValid = false;
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(ProgramID);
	spdlog::info("Shader Program {0} deleted successfully", ProgramID);
}

void ShaderProgram::Use()
{
	if (!bIsValid)
	{
		spdlog::error("Shader Program is not Valid!");
		return;
	}
	glUseProgram(ProgramID);
}

void ShaderProgram::Link()
{
	glLinkProgram(ProgramID);

	GLint Linked;
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Linked);
	if (!Linked)
	{
		bIsValid = false;

		GLsizei LogLength = 0;
		GLchar ErrorMsg[1024];
		glGetProgramInfoLog(ProgramID, 1024, nullptr, ErrorMsg);
		spdlog::error("Error while linking shader program: {0}", ErrorMsg);
		return;
	}

	bIsValid = true;
}

void ShaderProgram::Attach(const Shader & ShaderObj) const
{
	if (!ShaderObj.IsValid())
	{
		spdlog::error("ShaderObject is not valid!");
		return;
	}

	glAttachShader(ProgramID, ShaderObj.GetID());
}

void ShaderProgram::Detach(const Shader & ShaderObj) const
{
	glDetachShader(ProgramID, ShaderObj.GetID());
}

bool ShaderProgram::IsValid() const
{
	return bIsValid;
}

void ShaderProgram::SetBool(const std::string & Name, bool Value) const
{
	glUniform1i(glGetUniformLocation(ProgramID, Name.c_str()), Value);
}

void ShaderProgram::SetInt(const std::string & Name, int Value) const
{
	glUniform1i(glGetUniformLocation(ProgramID, Name.c_str()), Value);
}

void ShaderProgram::SetFloat(const std::string & Name, float Value) const
{
	glUniform1f(glGetUniformLocation(ProgramID, Name.c_str()), Value);
}
