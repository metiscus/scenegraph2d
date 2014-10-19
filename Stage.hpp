#ifndef STAGE_HPP_
#define STAGE_HPP_

#include "Camera.hpp"
#include "Vector.hpp"
#include "Rectangle.hpp"
#include "RefPtr.hpp"
#include <glm/glm.hpp>

class Stage : public Object
{
public:
	Stage();
	~Stage();
	
	void setRoot(RefPtr<Group> root);
	RefPtr<Group> getRoot();
	const RefPtr<Group>& getRoot() const;

	void setViewport(const Rectangle& vp);
	Rectangle getViewport() const;

	RefPtr<Camera> getCamera();
	const RefPtr<Camera>& getCamera() const;

	void setCamera(RefPtr<Camera> camera);

private:
	RefPtr<Group> mRoot;
	RefPtr<Camera> mCamera;
	Rectangle mViewport;
};



#endif // STAGE_HPP_
