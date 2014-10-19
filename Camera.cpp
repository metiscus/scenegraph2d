#include "Camera.hpp"
#include "Object.hpp"
#include "RefPtr.hpp"

Camera::Camera()
	: Object("camera")
{
    // the user expects y to be up
    setView(
    	glm::vec3(0., 0., 0.0f), 
    	glm::vec3(0., 0., -1.f),
        glm::vec3(0., 1., 0.f)
    );

    setOrthographic(0, 1, 0, 1, -1, 1);
}

void Camera::setOrthographic(float left, float right, float bottom, float top,
                             float zNear, float zFar)
{
    mProjectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);
}

void Camera::setView(const Vectorf& center)
{
    mViewMatrix = glm::lookAt(glm::vec3(center.x, center.y, 0.f), glm::vec3(center.x, center.y, 1.0f), glm::vec3(0.f, 1.f, 0.f));
}

const glm::mat4 &Camera::getProjectionMatrix() const
{
    return mProjectionMatrix;
}

const glm::mat4 &Camera::getViewMatrix() const
{
    return mViewMatrix;
}
