#define STB_IMAGE_IMPLEMENTATION
#include "Core.hpp"

typedef Graffiti::Core GC;
typedef Graffiti::Util GU;
typedef Graffiti::Window GW;
typedef Graffiti::Shader GS;
typedef Graffiti::ShaderType GSS;
typedef Graffiti::Mesh GM;
typedef Graffiti::Vertex GV;
typedef Graffiti::Texture GT;

int main() {
	// initializing Graffiti core
	GC::init();
	GW window(800, 600, "Test");
	window.setPolygonMode(false);

	GS ourShader;
	ourShader.attach("shaders/simple_trig.vert", GSS::VERTEX);
	ourShader.attach("shaders/simple_trig.frag", GSS::FRAGMENT);

	GT ourTexture;
	ourTexture.attach("assets/textures/lava_texture.jpg");

	//ObjLoader loader;
	//loader.load("assets/suzi.obj");

	std::vector<GV> vertices;
	vertices.push_back(GV{ glm::vec3{0.0f, 0.5f, 0.0f}, glm::vec2{ 0.5f, 1.0f } });
	vertices.push_back(GV{ glm::vec3{0.5f, -0.5f, 0.0f}, glm::vec2{ 1.0f, 0.0f } });
	vertices.push_back(GV{ glm::vec3{-0.5f, -0.5f, 0.0f}, glm::vec2{ 0.0f, 0.0f } });

	std::vector<unsigned int> indices;
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	GM ourMesh;
	ourMesh.attach(vertices, indices);


	// starting game loop
	while (!glfwWindowShouldClose(window.getWindow())) {
		// render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ourShader.use();		
		ourShader.setUniform3f("ourColor", glm::vec3{ 0.8f,0.8f,0.2f});
		ourTexture.use();
		ourMesh.Draw();

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		glfwSwapBuffers(window.getWindow());
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	glfwTerminate();
	return 0;

}