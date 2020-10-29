#include "Core.h"
#include "Shader.h"
#include "ShaderProgram.h"
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
	Shader shader3{ ShaderType::VERTEX, "cube.vs" };
	Shader shader4{ ShaderType::FRAGMENT, "cube.fs" };
	
	ShaderProgram ShaderProg1;
	ShaderProg1.Attach(shader1);
	ShaderProg1.Attach(shader2);
	ShaderProg1.Link();

	ShaderProgram ShaderProg2;
	ShaderProg2.Attach(shader3);
	ShaderProg2.Attach(shader4);
	ShaderProg2.Link();
	
	TestTriangle Triangle1;
	TestTriangle Triangle2;
	TestCube Cube;
	Cube.Init();
	Triangle1.Init();
	Triangle2.Init();
	

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(Core.GetWindow()))
	{
		Core.ClearBuffer();

	
		ShaderProg1.Use();

		Cube.Draw();



		glfwSwapBuffers(Core.GetWindow());
		glfwPollEvents();
	}

	Triangle1.Clear();
	Triangle2.Clear();
	Cube.Clear();

	Core.Exit();
	return 0;
}