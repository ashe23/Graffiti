#include "Core.hpp"

namespace Graffiti {
	void Core::init() {
		// loading GLFW
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	}

	void Core::enable3D() {
		glEnable(GL_DEPTH_TEST);
	}
}