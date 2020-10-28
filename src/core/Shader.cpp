#include <string>

#include "Shader.h"
#include "FileManager.h"
#include "Util.h"

#include "spdlog/spdlog.h"
#include <glm/gtc/type_ptr.hpp>



Shader::Shader(const char * VertShaderPath, const char * FragShaderPath)
{
	VertexShaderPath = VertShaderPath;
	FragmentShaderPath = FragShaderPath;

	this->Compile();
}

Shader::~Shader()
{
	glDeleteProgram(ID);
}

void Shader::Use()
{
	glUseProgram(ID);
}

unsigned int Shader::GetID() const
{
	return ID;
}

void Shader::SetBool(const std::string & Name, bool Value) const
{
	glUniform1i(glGetUniformLocation(ID, Name.c_str()), static_cast<int>(Value));
}

void Shader::SetInt(const std::string & Name, int Value) const
{
	glUniform1i(glGetUniformLocation(ID, Name.c_str()), Value);
}

void Shader::SetFloat(const std::string & Name, float Value) const
{
	glUniform1f(glGetUniformLocation(ID, Name.c_str()), Value);
}

void Shader::SetMatrix4(const std::string & Name, glm::mat4 Value) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, Name.c_str()), 1, GL_FALSE, glm::value_ptr(Value));
}

void Shader::CheckCompileError(unsigned int Shader, ShaderCompilationType Type)
{
	int status;
	char InfoLog[1024];

	if (Type == ShaderCompilationType::Program)
	{
		glGetShaderiv(Shader, GL_LINK_STATUS, &status);
	}
	else
	{
		glGetShaderiv(Shader, GL_COMPILE_STATUS, &status);
	}

	if (!status)
	{
		glGetProgramInfoLog(Shader, 1024, NULL, InfoLog);

		if (Type == ShaderCompilationType::Program)
		{
			spdlog::error("Error in shader program {0}", InfoLog);
		}
		else
		{
			spdlog::error("Error while compiling shader {0}", InfoLog);
		}
	}
}

void Shader::Compile()
{
	// read shader files content
	auto ShadersDir = Graffiti::FileManager::GetShadersDir();
	
	auto VertexShaderFile = ShadersDir + VertexShaderPath;
	auto FragmentShaderFile = ShadersDir + FragmentShaderPath;

	auto VertexShaderCode = Graffiti::Util::ReadFileContent(VertexShaderFile);
	auto FragmentShaderCode = Graffiti::Util::ReadFileContent(FragmentShaderFile);
	const char* vsc = VertexShaderCode.c_str();
	const char* fsc = FragmentShaderCode.c_str();
	// Creating shader objects
	VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertexShader, 1, &vsc, NULL);
	glCompileShader(VertexShader);
	this->CheckCompileError(VertexShader, ShaderCompilationType::Shader);

	FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragmentShader, 1, &fsc, NULL);
	glCompileShader(FragmentShader);
	this->CheckCompileError(FragmentShader, ShaderCompilationType::Shader);
	// create shader programm and link them
	ID = glCreateProgram();
	glAttachShader(ID, VertexShader);
	glAttachShader(ID, FragmentShader);
	glLinkProgram(ID);
	this->CheckCompileError(ID, ShaderCompilationType::Program);

	// delete shaders resources
	glDeleteShader(VertexShader);
	glDeleteShader(FragmentShader);
}
