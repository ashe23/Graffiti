#ifndef GRAFFITI_WAVE_FRONT_LOADER_H
#define GRAFFITI_WAVE_FRONT_LOADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>



struct Vertex {
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

class WaveFrontLoader {
public:
	void load(const std::string);
	GLuint getVAO();
private:
	GLuint VAO, VBO, EBO;
	void setupMesh();
	std::vector<Vertex> vertices;

};

#endif // GRAFFITI_WAVE_FRONT_LOADER_H