#include "Core.h"
#include "Shader.h"
#include "TestTriangle.h"
#include "TestCube.h"
#include "Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>


void KeyboardInputCallback(GLFWwindow* Window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(Window, GLFW_TRUE);
	}
}


int main()
{		
	Core Core;
	Core.Init();

	if (!Core.InitializedSuccessFully())
	{
		Core.Exit();
		return 0;
	}

	glfwSetKeyCallback(Core.GetWindow(), KeyboardInputCallback);
	glEnable(GL_DEPTH_TEST);

	//Shader TestShader{ "test.vs", "test.fs" };


	// creating first shader
	Shader shader1{ ShaderType::VERTEX , "test.vs"};	
	Shader shader2{ ShaderType::FRAGMENT, "test.fs" };
	//shader1.IsValid();

	// Camera MVP
	

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(Core.GetWindow()))
	{
		Core.ClearBuffer();

	


		glfwSwapBuffers(Core.GetWindow());
		glfwPollEvents();
	}

	Core.Exit();
	return 0;
}