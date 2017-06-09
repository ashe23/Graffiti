#pragma once
#ifndef GRAFFITI_CORE_HPP
#define GRAFFITI_CORE_HPP

// core libs
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

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
#include "Mesh.hpp"

namespace Graffiti {

    class Core {
    public:
        static void init();
    };
}

#endif // !GRAFFITI_CORE_HPP
