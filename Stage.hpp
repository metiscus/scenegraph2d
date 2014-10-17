#ifndef STAGE_HPP_
#define STAGE_HPP_

#include "RefPtr.hpp"

class Stage : public Object
{
public:
	Stage();
	~Stage();
	
	inline void setCamera(std::shared_ptr<Camera> camera);
	inline std::shared_ptr<Camera> getCamera();
	
	inline void addChild(std::shared_ptr<Node> child);
	inline void removeChild(std::shared_ptr<Node> child);
	inline unsigned int getNumChildren() const;

private:
	std::shared_ptr<Camera> mCamera;
	std::shared_ptr<Group>  mChildren;
};



#endif // STAGE_HPP_
