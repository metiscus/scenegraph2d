#include "Node.hpp"

Node::Node() 
	: Object("node")
	, mIsBoundDirty(false)
	, mIsEnabled(true)
{
	;
}

Node::~Node()
{
	;
}

Rectangle& Node::getBound()
{
	return mBoundingBox;
}

Rectangle Node::getBound() const
{
	return mBoundingBox;
}

void Node::dirtyBound()
{
	mIsBoundDirty = true;
}

void Node::setBound(const Rectangle& bound)
{
	mIsBoundDirty = false;
	mBoundingBox = bound;
}

void Node::computeBound()
{
	mIsBoundDirty = false;
}
	
bool Node::getEnabled() const
{
	return mIsEnabled;
}

void Node::setEnabled(bool enabled)
{
	mIsEnabled = enabled;
}
