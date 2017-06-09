#pragma once
#ifndef GRAFFITI_SHADER_HPP
#define GRAFFITI_SHADER_HPP

#include "Core.hpp"

namespace Graffiti {
    // Shader types
    enum ShaderType {
        VERTEX = GL_VERTEX_SHADER,
        FRAGMENT = GL_FRAGMENT_SHADER
    };

    /**
     * Shader loading class
     * Usage:
     *      Shader myshader;
     *      myshader.attach(shader_file_path,shaderType)
     *      myshader.use();
     */
    class Shader {
        GLuint _program;

        void compile();

        std::vector<GLuint> compiled_shaders;
    public:
        void attach(const char *, Graffiti::ShaderType);

        GLuint getProgram() const;

        void use();

        void setInt(const std::string &, int) const;

        void setMat4(const std::string &, const glm::mat4 &) const;

    };
}

#endif //GRAFFITI_SHADER_HPP