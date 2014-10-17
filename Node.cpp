#include "Node.hpp"

Node::Node(const char* name) 
	: Object(name)
	, mIsEnabled(true)
	, mIsBoundDirty(false)
{
	;
}

Node::~Node()
{
	;
}

Rectangle& Node::getBound()
{
	if(mIsBoundDirty)
	{
		computeBound();
	}
	
	return mBoundingBox;
}

Rectangle Node::getBound() const
{
	if(mIsBoundDirty)
	{
		computeBound();
	}
	
	return mBoundingBox;
}

void Node::dirtyBound() const
{
	mIsBoundDirty = true;
}

void Node::setBound(const Rectangle& bound)
{
	mIsBoundDirty = false;
	mBoundingBox = bound;
}

void Node::computeBound() const
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

void Node::addParent( RefPtr<Node> parent )
{
	mParents.push_back(parent);
}

void Node::removeParent( RefPtr<Node> parent )
{
    //\TODO: make this more efficient
    std::vector< RefPtr<Node> > newParents;
    newParents.reserve(mParents.size());
    
    for(unsigned int ii=0; ii<mParents.size(); ++ii)
    {
        if( mParents[ii].get() != parent.get() ) {
            newParents.push_back(mParents[ii]);
        }
    }
    
    mParents = newParents;	
}

std::vector< RefPtr<Node> > Node::getParents()
{
	return mParents;
}

RefPtr<Node> Node::getParentAtIndex(unsigned int index)
{
	return mParents[index];
}

const RefPtr<Node> Node::getParentAtIndex(unsigned int index) const
{
	return mParents[index];
}

unsigned int Node::getNumParents() const
{
	return mParents.size();
}
