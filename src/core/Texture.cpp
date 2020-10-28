#include "Texture.h"
#include "Core_Minimal.h"

Texture::Texture(const char * TP, bool Alpha)
{
	TexturePath = TP;
	WithAlpha = Alpha;
}

unsigned char * Texture::GetTextureData() const
{
	return TextureData;
}

void Texture::Load()
{
	auto EngineDir = Graf::Util::GetEngineDir();

	glGenTextures(1, &TextureID);
	glBindTexture(GL_TEXTURE_2D, TextureID); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	TextureData = stbi_load((EngineDir + TexturePath).c_str(), &width, &height, &ColorChannels, 0);
	if (TextureData)
	{
		auto ColorMode = WithAlpha ? GL_RGBA : GL_RGB;
		glTexImage2D(GL_TEXTURE_2D, 0, ColorMode, width, height, 0, ColorMode, GL_UNSIGNED_BYTE, TextureData);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << EngineDir + TexturePath << std::endl;
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(TextureData);
}

unsigned int Texture::GetTextureID() const
{
	return TextureID;
}
