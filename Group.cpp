#include "Group.hpp"

Group::Group(const char* name)
    : Node(name)
{
    
}

void Group::computeBound() const
{
    mBoundingBox.reset();
    for(unsigned int ii=0; ii<mChildren.size(); ++ii)
    {
        mBoundingBox.expandBy( mChildren[ii]->getBound() );
    }
    mIsBoundDirty = false;
}

void Group::addChild(RefPtr<Node> child)
{
    dirtyBound();
    mChildren.push_back(child);
    child->addParent(this);
}

unsigned int Group::getNumChildren() const
{
    return mChildren.size();
}

void Group::dirtyBound() const
{
    for(unsigned int ii=0; ii<mChildren.size(); ++ii)
    {
        mChildren[ii]->dirtyBound();
    }
}

const RefPtr<Node> Group::getChildAtIndex(unsigned int idx) const
{
    return mChildren[idx];
}

RefPtr<Node> Group::getChildAtIndex(unsigned int idx)
{
    return mChildren[idx];
}

void Group::removeChild(RefPtr<Node> child )
{
    //\TODO: make this more efficient
    std::vector< RefPtr<Node> > newChildren;
    newChildren.reserve(mChildren.size());
    
    for(unsigned int ii=0; ii<mChildren.size(); ++ii)
    {
        if( mChildren[ii].get() != child.get() ) {
            newChildren.push_back(mChildren[ii]);
        }
        else {
            mChildren[ii]->removeParent(this);
        }
    }
    
    mChildren = newChildren;
}

void Group::removeChildAtIndex(unsigned int idx)
{
    //\TODO: make this more efficient
    std::vector< RefPtr<Node> > newChildren;
    newChildren.reserve(mChildren.size());
    
    for(unsigned int ii=0; ii<mChildren.size(); ++ii)
    {
        if( ii != idx ) {
            newChildren.push_back(mChildren[ii]);
        }
        else {
            mChildren[ii]->removeParent(this);
        }
    }
    
    mChildren = newChildren;
}
