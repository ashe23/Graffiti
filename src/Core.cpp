#include "Core.hpp"

namespace Graffiti {
	void Core::init() {
		// loading GLFW
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);		
	}
		
	void Core::update() {
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
	}

	void Core::enable3D() {
		// NOTE: This should be called after window created otherwise it will Crash!
		glEnable(GL_DEPTH_TEST);
	}
}