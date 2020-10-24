#pragma once


namespace Display
{
	static constexpr int WIDTH = 1280;
	static constexpr int HEIGHT = 720;
};

class Core
{
public:
	int init();
	void loop();
private:
	struct GLFWwindow* window;
};