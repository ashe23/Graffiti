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
		// Stores compiles shader program ID
		GLuint _program;
		// Compiles shader program
		void compile();
		// Array of successfully compiled shaders , but not attached to program yet.
		std::vector<GLuint> compiled_shaders;
	public:
		GLuint getProgram() const;
		void use();
		void attach(const std::string &, Graffiti::ShaderType);

		// Shader Utility functions
		void setInt(const std::string &, int) const;
		void setBool(const std::string &, bool) const;
		void setFloat(const std::string &, float) const;
		void setUniform3f(const std::string &, const glm::vec3 &) const;
		void setMat4(const std::string &, const glm::mat4 &) const;

	};
}

#endif //GRAFFITI_SHADER_HPP