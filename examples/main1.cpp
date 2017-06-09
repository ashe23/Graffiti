#include "Core.hpp"

typedef Graffiti::Core GC;
typedef Graffiti::Util GU;
typedef Graffiti::Window GW;
typedef Graffiti::Shader GS;
typedef Graffiti::ShaderType GSS;
typedef Graffiti::Mesh GM;
typedef Graffiti::Vertex GV;

int main() {
    // initializing Graffiti core
    GC::init();
    GW window(800, 600, "Test");
    window.setPolygonMode(true);

    GS ourShader;
    ourShader.attach(GU::getPath("shaders/simple_trig.vert").c_str(), GSS::VERTEX);
    ourShader.attach(GU::getPath("shaders/simple_trig.frag").c_str(), GSS::FRAGMENT);

    std::vector<GV> vertices;
    vertices.push_back(Graffiti::Vertex{glm::vec3{0.5f, 0.5f, 0.0f}});
    vertices.push_back(Graffiti::Vertex{glm::vec3{0.5f, -0.5f, 0.0f}});
    vertices.push_back(Graffiti::Vertex{glm::vec3{-0.5f, -0.5f, 0.0f}});
    vertices.push_back(Graffiti::Vertex{glm::vec3{-0.5f, 0.5f, 0.0f}});

    std::vector<unsigned int> indices;
    indices.push_back(0);
    indices.push_back(2);
    indices.push_back(3);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(3);

    GM mesh;
    mesh.attach(vertices, indices);



    // starting game loop
    while (!glfwWindowShouldClose(window.getWindow())) {
        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ourShader.use();

        mesh.Draw();
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window.getWindow());
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;

}