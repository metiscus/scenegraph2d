#include "Camera.hpp"
#include "Group.hpp"
#include "Node.hpp"
#include "Object.hpp"
#include "Program.hpp"
#include "Shader.hpp"
#include "Stage.hpp"

Stage::Stage()
	: Object("stage")
	, mRoot( new Group() )
	, mCamera( new Camera() )
	, mProgram( new Program() )
	, mVertexShader( new Shader(Shader::Vertex) )
	, mFragmentShader( new Shader(Shader::Fragment) )
	, mProjectionMatrix( new Uniform(Uniform::Uniform_mat4, "projectionMat") )
	, mModelViewMatrix( new Uniform(Uniform::Uniform_mat4, "modelViewMat") )
{
	mProjectionMatrix->set( mCamera->getProjectionMatrix() );
	mModelViewMatrix->set( mCamera->getViewMatrix() );
	
	mFragmentShader->loadFile("stage_frag.glsl");
	mFragmentShader->compile();
	
	mVertexShader->loadFile("stage_vert.glsl");
	mVertexShader->compile();
	
	mProgram->addShader(mFragmentShader);
	mProgram->addShader(mVertexShader);
	mProgram->addUniform(mProjectionMatrix);
	mProgram->addUniform(mModelViewMatrix);
	mProgram->link();
}

Stage::~Stage()
{
	;
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

void Stage::draw()
{
	mProgram->use();
}
