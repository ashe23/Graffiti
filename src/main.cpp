//#include "Core_Minimal.h"
#include "Core.h"

using namespace std;

int main()
{		
	Core Core;
	Core.Init();

	if (!Core.InitializedSuccessFully())
	{
		Core.Exit();
		return 0;
	}

	while (!glfwWindowShouldClose(Core.GetWindow()))
	{
		glClearColor(0.082f, 0.317f, 0.250f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(Core.GetWindow());
		glfwPollEvents();
	}

	Core.Exit();
	return 0;
}