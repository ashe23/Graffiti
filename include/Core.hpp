#pragma once
#ifndef GRAFFITI_CORE_HPP
#define GRAFFITI_CORE_HPP

// core libs
#include <iostream>
#include <string>
#include <vector>

// opengl libs
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// stb image lib
//#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>

// glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// filesystem libs
#include <filesystem/path.h>
#include <filesystem/resolver.h>

// Graffiti libs
#include "Shader.hpp"
#include "Util.hpp"
#include "Window.hpp"

namespace Graffiti {
	
	class Core {
	public:		
		static void init() {			
			// loading GLFW
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		}
	};
}

#endif // !GRAFFITI_CORE_HPP
