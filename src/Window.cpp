#include "Window.hpp"

namespace Graffiti {
    Window::Window(unsigned int width, unsigned int height, const std::string &title) {
        // creating window
        window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        if (!window) {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
        glfwMakeContextCurrent(window);

        // glad: load all OpenGL function pointers
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            glfwTerminate();
        }

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
}