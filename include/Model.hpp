#pragma once
#ifndef GRAFFITI_MODEL_HPP
#define GRAFFITI_MODEL_HPP

#include "Core.hpp"

namespace Graffiti {

	class Shader;
	class Mesh;
	struct MeshTexture;

	unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);

	class Model {
	public:
		/*  Model Data */			
		std::vector<Mesh> meshes;
		std::string directory;
		bool gammaCorrection;
		// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
		std::vector<MeshTexture> textures_loaded;
		Model(std::string const &, bool);
		void Draw(Shader);
	private:
		void loadModel(std::string);
		void processNode(aiNode *, const aiScene *);
		Mesh processMesh(aiMesh *, const aiScene *);
		std::vector<MeshTexture> loadMaterialTextures(aiMaterial *, aiTextureType, std::string);
	};
}

#endif //GRAFFITI_MODEL_HPP