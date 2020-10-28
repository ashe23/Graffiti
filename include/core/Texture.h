#pragma once

class Texture
{
public:
	Texture(const char* TP, bool Alpha);
	unsigned char* GetTextureData() const;
	void Load();
	unsigned int GetTextureID() const;
private:
	int width;
	int height;
	int ColorChannels;
	unsigned char* TextureData = nullptr;
	const char* TexturePath;
	unsigned int TextureID;
	bool WithAlpha;
};