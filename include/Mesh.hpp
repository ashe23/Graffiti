#pragma once
#ifndef GRAFFITI_MESH_HPP
#define GRAFFITI_MESH_HPP

#include "Core.hpp"

namespace Graffiti {
	class Shader;

	struct Vertex {
		// position
		glm::vec3 Position;
		// normal
		glm::vec3 Normal;
		// texCoords
		glm::vec2 TexCoords;
		// tangent
		glm::vec3 Tangent;
		// bitangent
		glm::vec3 Bitangent;
	};

	struct MeshTexture {
		unsigned int id;
		std::string type;
		aiString path;
	};

	class Mesh {
	public:
		/*  Mesh Data  */
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<MeshTexture> textures;
		unsigned int VAO;
		/*  Functions  */
		// constructor
		Mesh(std::vector<Vertex>, std::vector<unsigned int>, std::vector<MeshTexture>);
		void Draw(Shader);
	private:
		/*  Render data  */
		unsigned int VBO, EBO;
		void setupMesh();
	};
}

#endif // !GRAFFITI_MESH_HPP


