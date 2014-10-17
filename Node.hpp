#ifndef NODE_HPP_
#define NODE_HPP_

#include "Object.hpp"
#include "Rectangle.hpp"

class Group;
class Transform;

#include <vector>

class Node : public Object
{
public:
	Node(const char* name = "node");
	virtual ~Node();
	
	virtual inline Node* asNode();
	virtual inline Group* asGroup();
	virtual inline Transform* asTransform();

	Rectangle& getBound();
	Rectangle getBound() const;
	virtual void dirtyBound() const;
	void setBound(const Rectangle& bound);
	
	virtual void computeBound() const;

	bool getEnabled() const;
	void setEnabled(bool enabled);

	void addParent( RefPtr<Node> parent );
	void removeParent( RefPtr<Node> parent );
	std::vector< RefPtr<Node> > getParents();
	RefPtr<Node> getParentAtIndex(unsigned int index);
	const RefPtr<Node> getParentAtIndex(unsigned int index) const;
	unsigned int getNumParents() const;

protected:
    bool mIsEnabled;
	mutable bool mIsBoundDirty;
	mutable Rectangle mBoundingBox;
	
	std::vector< RefPtr<Node> > mParents;
};

inline Node* Node::asNode()
{
	return this;
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
