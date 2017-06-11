#pragma once
#ifndef GRAFFITI_CAMERA_HPP
#define GRAFFITI_CAMERA_HPP

#include "Core.hpp"

namespace Graffiti {
	class Camera {
	public:
		glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);	
	};
}

#endif //GRAFFITI_CAMERA_HPP