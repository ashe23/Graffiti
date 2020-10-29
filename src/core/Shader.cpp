#include <string>

#include "Shader.h"
#include "FileManager.h"
#include "Util.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

#include <glm/gtc/type_ptr.hpp>



Shader::Shader(ShaderType Type, const char * Path)
{
	bIsValid = false;
	this->Type = Type;
	ShaderFilePath = Path;

	this->Init();
}

bool Shader::IsValid() const
{
	return bIsValid;
}

GLuint Shader::GetID() const
{
	return ShaderObjectID;
}

void Shader::Init()
{
	// todo::ashe23 should we check file extension type for shader files?

	// 1) Read Shader Code from file
	std::string ShaderCodeStr = ReadShaderCodeFromFile();
	const char* ShaderCode = ShaderCodeStr.c_str();
	// 2) Create Shader Object
	auto ShaderType = (Type == ShaderType::VERTEX) ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;
	ShaderObjectID = glCreateShader(ShaderType);
	// 3) Fill Code from file to Shader Object
	glShaderSource(ShaderObjectID, 1, &ShaderCode, nullptr);
	// 4) Compile Shader Object
	glCompileShader(ShaderObjectID);
	// 5) Check for errors
	this->CheckCompileError();
}

std::string Shader::ReadShaderCodeFromFile()
{
	auto RootDir = Graffiti::FileManager::GetShadersDir();
	ShaderFilePath = RootDir + ShaderFilePath;

	return Graffiti::Util::ReadFileContent(ShaderFilePath);
}

void Shader::CheckCompileError()
{
	GLint Compiled;	
	glGetShaderiv(ShaderObjectID, GL_COMPILE_STATUS, &Compiled);

	if (!Compiled)
	{
		GLsizei LogLength = 0;
		GLchar Msg[1024];
		glGetShaderInfoLog(ShaderObjectID, 1024, &LogLength, Msg);
		spdlog::error("Error while compiling shader {0}", Msg);
		bIsValid = false;
		return;
	}

	bIsValid = true;
}
