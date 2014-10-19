#include "Group.hpp"
#include "Node.hpp"
#include "Object.hpp"
#include "Stage.hpp"

Stage::Stage()
	: Object("stage")
{
	
}

Stage::~Stage()
{
	
}

void Stage::setRoot(RefPtr<Group> root)
{
	mRoot = root;
}

RefPtr<Group> Stage::getRoot()
{
	return mRoot;
}

const RefPtr<Group>& Stage::getRoot() const
{
	return mRoot;
}

void Stage::setViewport(const Rectangle& vp)
{
	mViewport = vp;
}

Rectangle Stage::getViewport() const
{
	return mViewport;
}

RefPtr<Camera> Stage::getCamera()
{
	return mCamera;	
}

const RefPtr<Camera>& Stage::getCamera() const
{
	return mCamera;
}

void Stage::setCamera(RefPtr<Camera> camera)
{
	mCamera = camera;
}

