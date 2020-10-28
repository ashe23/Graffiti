#include "Core.h"
#include "Shader.h"
#include "TestTriangle.h"
#include "Texture.h"

int main()
{		
	Core Core;
	Core.Init();

	if (!Core.InitializedSuccessFully())
	{
		Core.Exit();
		return 0;
	}


	Shader TestShader{ "test.vs", "test.fs" };
	TestTriangle Triangle;
	Triangle.Init();

	while (!glfwWindowShouldClose(Core.GetWindow()))
	{
		Core.ClearBuffer();

		TestShader.Use();

		Triangle.Draw();

		glfwSwapBuffers(Core.GetWindow());
		glfwPollEvents();
	}

	Triangle.Clear();
	Core.Exit();
	return 0;
}