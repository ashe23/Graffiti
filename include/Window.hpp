#pragma once
#ifndef GRAFFITI_WINDOW_HPP
#define GRAFIITI_WINDOW_HPP

#include "Core.hpp"

namespace Graffiti {
    class Window {
        unsigned int majorVersion;
        unsigned int minorVersion;
        GLFWwindow *window;
    public:
        Window(unsigned int width, unsigned int height, const std::string &title);

        GLFWwindow *getWindow();

        void setPolygonMode(bool);

	    void setVersion(const unsigned int, const unsigned int);
    };
}

#endif // !GRAFFITI_WINDOW_HPP
