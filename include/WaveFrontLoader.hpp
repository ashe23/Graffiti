#ifndef WAVE_FRONT_LOADER_H
#define WAVE_FRONT_LOADER_H

bool loadOBJ(
	const char * path, 
	std::vector<glm::vec3> & out_vertices, 
	std::vector<glm::vec2> & out_uvs, 
	std::vector<glm::vec3> & out_normals
);
#endif // WAVE_FRONT_LOADER_H