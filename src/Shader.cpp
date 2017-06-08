//
// Created by ashe23 on 27.05.17.
//

#include "Shader.hpp"

std::string shaderTypeToStr(ShaderType type) {
    switch (type) {
        case ShaderType::VERTEX:
            return "VERTEX";
        case ShaderType::FRAGMENT:
            return "FRAGMENT";
    }
    return "Unknown";
}

/**
 * Accepts shader path and type.
 * 1) Reads shader code from file
 * 2) Compiling shader
 * 3) Storing shaders in stack
 * 4) Throws Errors if any
 * @param shaderPath
 * @param type
 */
void Shader::attach(const char *shaderPath, ShaderType type) {
    // 1) Reading file content
    std::ifstream file(shaderPath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file!\n";
    }

    std::string shaderCodeStr((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    const GLchar *shaderCode = shaderCodeStr.c_str();

    // 2) Compiling shader
    GLuint shaderId;
    GLint success;
    GLchar infoLog[512];

    shaderId = glCreateShader(type);
    glShaderSource(shaderId, 1, &shaderCode, NULL);
    glCompileShader(shaderId);
    // Print compile errors if any
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // storing successfully compiled shader in vector
    compiled_shaders.push_back(shaderId);
}

/**
 * Creating and compiling shader program
 */
void Shader::compile() {
    // Creating Shader Program
    this->_program = glCreateProgram();
    // Attaching shaders to program
    for (auto shader : compiled_shaders) {
        glAttachShader(this->_program, shader);
    }
    glLinkProgram(this->_program);
    GLint success;
    GLchar infoLog[512];
    // Print linking errors if any
    glGetProgramiv(this->_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->_program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // Delete the shaders as they're linked into our program now and no longer necessary
    for (auto shader : compiled_shaders) {
        glDeleteShader(shader);
    }
}

/**
 * Return compiled shader program
 * @return
 */
GLuint Shader::getProgram() const {
    return this->_program;
}

/**
 * Using shader program
 */
void Shader::use() {
    this->compile();	
    glUseProgram(this->_program);
}

void Shader::setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(this->_program, name.c_str()), value);
}

void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const {
    glUniformMatrix4fv(glGetUniformLocation(this->_program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}


