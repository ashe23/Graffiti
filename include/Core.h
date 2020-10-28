#pragma once
#include <functional>

namespace Display
{
	// todo:ashe23 move this to .config file
	static constexpr int WIDTH = 1280;
	static constexpr int HEIGHT = 720;
};

namespace Config
{
	static constexpr int MAJOR = 4;
	static constexpr int MINOR = 5;
	static constexpr char* WINDOW_TITLE = "Graffiti 1.0";
}

typedef std::function<void()> TLoopCallbackFunc;
struct GLFWwindow;


class Core
{
public:	
	void Init();
	void Loop();
	void SetLoopCallbackFunc(const TLoopCallbackFunc& Fn);
private:
	GLFWwindow* Window;
	bool bInitSuccess = false;
	TLoopCallbackFunc LoopCallbackFunc;
private:
	bool InitGlad() const;
	static void OnWindowResize(GLFWwindow* Window, int Width, int Height);
	static void OnInputEvent(GLFWwindow* Window);
};