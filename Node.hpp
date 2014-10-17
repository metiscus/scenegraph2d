#ifndef NODE_HPP_
#define NODE_HPP_

#include "Object.hpp"
#include "Rectangle.hpp"

class Camera;
class Group;
class Transform;

class Node : public Object
{
public:
	Node();
	virtual ~Node();
	
	virtual inline Node* asNode();
	virtual inline Camera* asCamera();
	virtual inline Group* asGroup();
	virtual inline Transform* asTransform();

	Rectangle& getBound();
	Rectangle getBound() const;
	void dirtyBound();
	void setBound(const Rectangle& bound);
	
	virtual void computeBound();

	bool getEnabled() const;
	void setEnabled(bool enabled);

private:
    bool mIsEnabled;
	bool mIsBoundDirty;
	Rectangle mBoundingBox;
};

inline Node* Node::asNode()
{
	return this;
}

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
