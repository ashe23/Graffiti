#pragma once
#ifndef GRAFFITI_WINDOW_HPP
#define GRAFIITI_WINDOW_HPP

#include "Core.hpp"

namespace Graffiti {
	class Window {
		GLFWwindow *window;
	public:
		Window(unsigned int width, unsigned int height, const std::string &title, bool);
		GLFWwindow *getWindow();
		void setPolygonMode(bool);
	};
}

#endif // !GRAFFITI_WINDOW_HPP
