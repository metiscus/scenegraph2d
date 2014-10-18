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
	mIsBoundDirty = false;

	// iterate through the children and get bounding boxes

}
