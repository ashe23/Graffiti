#include "Core.h"
#include "Core_Minimal.h"
#include "Util.h"
#include <iostream>

void Core::Init()
{
	bInitSuccess = false;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Config::MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Config::MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Window = glfwCreateWindow(Display::WIDTH, Display::HEIGHT, Config::WINDOW_TITLE, nullptr, nullptr);
	if (!Window)
	{
		Graf::Util::PrintErrMsg("Failed to create GLFW window");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(Window);
	glfwSetFramebufferSizeCallback(Window, &Core::OnWindowResize);

	bInitSuccess = this->InitGlad();
}

void Core::Loop()
{
	if (!bInitSuccess)
	{
		Graf::Util::PrintErrMsg("Core initialization failed!");
		return;
	}


	while (!glfwWindowShouldClose(Window))
	{
		// Handling Inputs
		Core::OnInputEvent(Window);		

		if (LoopCallbackFunc)
		{
			LoopCallbackFunc();
		}		

		glfwSwapBuffers(Window);
		glfwPollEvents();
	}

	glfwTerminate();
}

void Core::SetLoopCallbackFunc(const TLoopCallbackFunc & fn)
{
	LoopCallbackFunc = fn;
}

bool Core::InitGlad() const
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		Graf::Util::PrintErrMsg("Failed to initialize GLAD");
		return false;
	}

	return true;
}

void Core::OnWindowResize(GLFWwindow* Window, int Width, int Height)
{
	glViewport(0, 0, Width, Height);
}

void Core::OnInputEvent(GLFWwindow * Window)
{
	if (glfwGetKey(Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(Window, true);
}
