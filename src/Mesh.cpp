//
// Created by ashe23 on 09.06.17.
//

#include "Mesh.hpp"

namespace Graffiti {

//    void Mesh::Draw() {
//        // draw mesh
//        glBindVertexArray(VAO);
//        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
//        glBindVertexArray(0);
//    }
//
//    void Mesh::attach(std::vector<Graffiti::Vertex> vertices, std::vector<unsigned int> indices) {
//        this->vertices = vertices;
//        this->indices = indices;
//
//        // now that we have all the required data, set the vertex buffers and its attribute pointers.
//        setupMesh();
//    }
//
//    void Mesh::setupMesh() {
//        // create buffers/arrays
//        glGenVertexArrays(1, &VAO);
//        glGenBuffers(1, &VBO);
//        glGenBuffers(1, &EBO);
//
//        glBindVertexArray(VAO);
//        // load data into vertex buffers
//        glBindBuffer(GL_ARRAY_BUFFER, VBO);
//        // A great thing about structs is that their memory layout is sequential for all its items.
//        // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
//        // again translates to 3/2 floats which translates to a byte array.
//        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
//
//        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
//
//        // set the vertex attribute pointers
//        // vertex Positions
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) 0);
//        // vertex texture coords
//        glEnableVertexAttribArray(1);
//        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, TexCoords));
//
//        glBindVertexArray(0);
//    }
}