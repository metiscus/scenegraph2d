#ifndef STAGE_HPP_
#define STAGE_HPP_

#include "Object.hpp"
#include "Vector.hpp"
#include "Rectangle.hpp"
#include "RefPtr.hpp"
#include <glm/glm.hpp>

class Group;
class Camera;
class Program;
class Uniform;
class Shader;

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

	void draw();

private:
	RefPtr<Group> mRoot;
	RefPtr<Camera> mCamera;
	Rectangle mViewport;
	RefPtr<Program> mProgram;
	RefPtr<Shader> mVertexShader;
	RefPtr<Shader> mFragmentShader;
	RefPtr<Uniform> mProjectionMatrix;
	RefPtr<Uniform> mModelViewMatrix;
};



#endif // STAGE_HPP_
