#ifndef NODE_HPP_
#define NODE_HPP_

#include "Object.hpp"

class Camera;
class Group;
class Transform;

class Node : public Object
{
public:
	Node();
	virtual ~Node();
	
	virtual inline Camera* asCamera();
	virtual inline Group* asGroup();
	virtual inline Transform* asTransform();

private:


};


inline Camera* Node::asCamera()
{
	return NULL;
}

inline Group* Node::asGroup()
{
	return NULL;
}

inline Transform* Node::asTransform()
{
	return NULL;
}

#endif // NODE_HPP_
