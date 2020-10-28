#include "ViewportCamera.h"

ViewportCamera::ViewportCamera()
{
	Position = glm::vec3(0.0f);
	WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	Front = glm::vec3(0.0f, 0.0f, -1.0f);
	CameraSpeed = 2.5f;
}

glm::mat4 ViewportCamera::GetViewMatrix()
{
	return glm::lookAt(Position, Position + Front, Up);
}
