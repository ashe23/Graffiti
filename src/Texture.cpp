#include "Texture.hpp"

namespace Graffiti {
	void Texture::attach(const std::string &texturePath) {
		// generate texture
		glGenTextures(1, &this->_textureID);
		glBindTexture(GL_TEXTURE_2D, _textureID);
		// set the texture wrapping/filtering options (on the currently bound texture object)		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// load and generate the texture(image)
		int width, height, nrChannels;
		unsigned char *data = stbi_load(Graffiti::Util::getPath(texturePath).c_str(), &width, &height, &nrChannels, 0);
		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			std::cout << "Failed to load texture" << std::endl;
		}

		// free resources
		stbi_image_free(data);
	}

	unsigned int Texture::getTexture() const {
		return this->_textureID;
	}

	void Texture::use() {
		glBindTexture(GL_TEXTURE_2D, _textureID);
	}
}