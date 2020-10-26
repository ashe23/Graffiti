#include "Core_Minimal.h"
#include "Util.h"
#include "Shader.h"
#include <iostream>
#include <filesystem>


Shader::Shader(const char * VertShaderPath, const char * FragShaderPath)
{
	VertexShaderPath = VertShaderPath;
	FragmentShaderPath = FragShaderPath;

	// todo:ashe23 this should be in different agnostic class
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
			std::cerr << "Error in shader program:" << InfoLog << std::endl;
		}
		else
		{
			std::cerr << "Error while compiling shader:" << InfoLog << std::endl;
		}
	}
}

void Shader::Compile()
{
	// read shader files content
	namespace fs = std::filesystem;
	std::filesystem::path path = fs::current_path();
	auto EngineDir = path.parent_path().u8string();
	auto VertexShaderFile = EngineDir + "/" + VertexShaderPath;
	auto FragmentShaderFile = EngineDir + "/" + FragmentShaderPath;
	bool isFile = std::filesystem::is_regular_file(EngineDir + VertexShaderPath);

	auto VertexShaderCode = Graf::Util::ReadFileContent(VertexShaderFile);
	auto FragmentShaderCode = Graf::Util::ReadFileContent(FragmentShaderFile);
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
