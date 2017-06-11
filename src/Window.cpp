#include "Window.hpp"

namespace Graffiti {
	// TODO:ashe23  make this function part of window class
	void framebufferSizeCallback(GLFWwindow *window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void inputCallback(GLFWwindow *window) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		// TODO:ashe23 add movement later
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			std::cout << "AA" << std::endl;
		
	}

	Window::Window(unsigned int width, unsigned int height, const std::string &title) {
		// creating window
		window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (!window) {
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(window);

		// glad: load all OpenGL function pointers
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD" << std::endl;
			glfwTerminate();
		}

		// initialize camera

		// set framesizecallback
		glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

		std::cout << glGetString(GL_VERSION) << std::endl;

	}

	GLFWwindow *Window::getWindow() {
		return window;
	}

	/**
	 * Activates Polygon mode
	 * @param mode
	 */
	void Window::setPolygonMode(bool mode) {
		if (mode) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
	}

	// Reads user input
	void Window::readUserInput() {
		inputCallback(this->window);
	}

	// Whenever windows sizes changes , updates its content according to new sizes
	/*void Window::framebufferSizeCallback(GLFWwindow *window, int width, int height) {
		glViewport(0, 0, width, height);
	}*/
}