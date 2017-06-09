#include "Core.hpp"

typedef Graffiti::Core GC;
typedef Graffiti::Util GU;
typedef Graffiti::Window GW;

int main() {
	// initializing Graffiti core
	GC::init();
	GW window(800, 600, "Test");

	// starting game loop
	while (!glfwWindowShouldClose(window.getWindow()))
	{	
		// render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		glfwSwapBuffers(window.getWindow());
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	glfwTerminate();
	return 0;

}