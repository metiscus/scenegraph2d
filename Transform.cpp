#include "Transform.hpp"

Transform::Transform()
    : Group("transform")
{
    ;
}

void Transform::setMatrix( const Matrix& matrix )
{
    mTransform = matrix;
}

Matrix& Transform::getMatrix()
{
    return mTransform;
}

const Matrix& Transform::getMatrix() const
{
    return mTransform;
}

void Transform::computeBound() const
{
    mBoundingBox.reset();

	// iterate through the children and get bounding boxes
    for(unsigned int ii=0; ii<mChildren.size(); ++ii)
    {
    	mBoundingBox.expandBy( mChildren[ii]->getBound().transformBy(mTransform) );
    }
    mIsBoundDirty = false;
}
