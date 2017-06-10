#ifndef GRAFFITI_MESH_HPP
#define GRAFFITI_MESH_HPP

#include "Core.hpp"

namespace Graffiti {
    struct Vertex {
        // position
        glm::vec3 Position;
        // texCoords
        glm::vec2 TexCoords;		
    };

    class Mesh {
    public:
        ~Mesh();

        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        unsigned int VAO;

        void attach(std::vector<Graffiti::Vertex>, std::vector<unsigned int>);

//        Mesh(std::vector<Graffiti::Vertex>, std::vector<unsigned int>);

        void Draw();

    private:
        unsigned int VBO, EBO;

        void setupMesh();
    };


}

#endif //GRAFFITI_MESH_HPP
