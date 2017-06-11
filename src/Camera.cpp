//#include "Camera.hpp"
//
//using namespace Graffiti;
//
//Camera::Camera(
//        glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
//        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
//        GLfloat yaw = YAW,
//        GLfloat pitch = PITCH
//) {
//    this->Position = position;
//    this->WorldUp = up;
//    this->Yaw = yaw;
//    this->Pitch = pitch;
//    this->updateCameraVectors();
//}
//
//Camera::Camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw,
//               GLfloat pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)),
//                                MovementSpeed(SPEED),
//                                MouseSensitivity(SENSITIVITY),
//                                Zoom(ZOOM) {
//    this->Position = glm::vec3(posX, posY, posZ);
//    this->WorldUp = glm::vec3(upX, upY, upZ);
//    this->Yaw = yaw;
//    this->Pitch = pitch;
//    this->updateCameraVectors();
//}
//
//// Returns the view matrix calculated using Eular Angles and the LookAt Matrix
//glm::mat4 Camera::GetViewMatrix() {
//    return glm::lookAt(this->Position, this->Position + this->Front, this->Up);
//}
//
//void Camera::ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime) {
//    GLfloat velocity = this->MovementSpeed * deltaTime;
//    if (direction == FORWARD)
//        this->Position += this->Front * velocity;
//    if (direction == BACKWARD)
//        this->Position -= this->Front * velocity;
//    if (direction == LEFT)
//        this->Position -= this->Right * velocity;
//    if (direction == RIGHT)
//        this->Position += this->Right * velocity;
//}
//
