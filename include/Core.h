#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

struct GLFWwindow;


class Core
{	
public:	
	void Init();
	void Exit();
	bool InitializedSuccessFully() const;
	void ClearBuffer();
	void InputHandler();
	GLFWwindow* GetWindow() const;
private:
	GLFWwindow* Window;
	bool bInitSuccess = false;
private:
	bool InitGlad() const;
	static void OnWindowResize(GLFWwindow* Window, int Width, int Height);
};