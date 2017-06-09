#include "WaveFrontLoader.hpp"

namespace StringLib {
	template<typename Out>
	void split(const std::string &s, char delim, Out result) {
		std::stringstream ss;
		ss.str(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			*(result++) = item;
		}
	}
	std::vector<std::string> split(const std::string &s, char delim) {
		std::vector<std::string> elems;
		split(s, delim, std::back_inserter(elems));
		return elems;
	}
}

void WaveFrontLoader::load(const std::string objFilePath)
{
	using namespace std;
	// Try to open file
	ifstream file;
	file.open(objFilePath);
	if (!file) {
		std::cerr << "Failed to open .obj file!\n";		
	}

	vector<string> tokens;
	string line;
	while (std::getline(file, line)) {
		istringstream iss(line);
		tokens = StringLib::split(line, ' ');
		// if prefix is "v" , then is vertex and we should grab them
		if (tokens.at(0) == "v") {
			GLfloat x = ::atof(tokens.at(1).c_str());
			GLfloat y = ::atof(tokens.at(2).c_str());
			GLfloat z = ::atof(tokens.at(3).c_str());
			vertices.push_back(Vertex{ x,y,z });
		}
	}	
	std::cout << "Obj file parse successfull. Total " << vertices.size() << " vertices loaded." << endl;
	std::cout << "Setup mesh" << endl;
	for (auto vert : vertices) {
		std::cout << vert.x << ":" << vert.y << ":" << vert.z << endl;
	}
	this->setupMesh();

}

GLuint WaveFrontLoader::getVAO()
{
	return VAO;
}

void WaveFrontLoader::setupMesh()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);	

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
	std::cout << sizeof(Vertex) << std::endl;

	// vertex positions
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);

	// unbind buffer
	glBindVertexArray(0);
}