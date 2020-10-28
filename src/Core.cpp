#include "Core.h"
#include "spdlog/spdlog.h"

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
		spdlog::error("Failed to create GLFW window");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(Window);
	glfwSetFramebufferSizeCallback(Window, &Core::OnWindowResize);

	bInitSuccess = this->InitGlad();
}

void Core::Exit()
{
	glfwTerminate();
}


bool Core::InitializedSuccessFully() const
{
	return bInitSuccess;
}

void Core::ClearBuffer()
{
	glClearColor(0.082f, 0.317f, 0.250f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

bool Core::InitGlad() const
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		spdlog::error("Failed to initialize GLAD");
		return false;
	}

	return true;
}

void Core::OnWindowResize(GLFWwindow* Window, int Width, int Height)
{
	glViewport(0, 0, Width, Height);
}

GLFWwindow * Core::GetWindow() const
{
	return Window;
}