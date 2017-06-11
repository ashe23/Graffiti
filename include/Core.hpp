#pragma once
#ifndef GRAFFITI_CORE_HPP
#define GRAFFITI_CORE_HPP

// assimp
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

// stb image lib
#include "stb_image.h"

// core libs
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

// opengl libs
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// filesystem libs
#include <filesystem/path.h>
#include <filesystem/resolver.h>

// Graffiti libs
#include "Window.hpp"
#include "Shader.hpp"
#include "Util.hpp"
#include "Model.hpp"
#include "Texture.hpp"
#include "Camera.hpp"
//#include "Mesh.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

namespace Graffiti {

	class Core {
	public:
		// timing
		float deltaTime = 0.0f;	// time between current frame and last frame
		float lastFrame = 0.0f;

		// Ticks every second 
		void init();
		// Updates times 
		void update();
		// Activates depth and going to 3D
		void enable3D();
	};
}

#endif // !GRAFFITI_CORE_HPP
