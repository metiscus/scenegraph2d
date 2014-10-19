#ifndef CAMERA_H_
#define CAMERA_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "Object.hpp"
#include "Vector.hpp"

class Camera : public Object
{
public:
    Camera();
    void setOrthographic(float left, float right, float bottom, float top, float zNear, float zFar);
    void setView(const Vectorf& center);

    const glm::mat4& getProjectionMatrix() const;
    const glm::mat4& getViewMatrix() const;

private:
    glm::mat4 mProjectionMatrix;
    glm::mat4 mViewMatrix;
};

#endif /* CAMERA_H_ */
