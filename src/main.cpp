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
	ShaderProg1.Attach(shader3);
	ShaderProg1.Attach(shader4);
	ShaderProg1.Link();

	
	
	TestCube Cube;
	Cube.Init();
	

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	ShaderProg1.Use();
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	proj = glm::perspective(glm::radians(60.0f), static_cast<float>(Display::WIDTH/ Display::HEIGHT), 0.1f, 100.0f);
	ShaderProg1.SetMat4("view", view);
	ShaderProg1.SetMat4("proj", proj);

	while (!glfwWindowShouldClose(Core.GetWindow()))
	{
		Core.ClearBuffer();

		ShaderProg1.Use();

		for (int i = 0; i < 10; ++i)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * i;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			ShaderProg1.SetMat4("model", model);			
			Cube.Draw();
		}




		glfwSwapBuffers(Core.GetWindow());
		glfwPollEvents();
	}

	Cube.Clear();

	Core.Exit();
	return 0;
}