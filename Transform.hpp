#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Group.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

class Transform : public Group
{
public:
    Transform();
    
    virtual inline Transform* asTransform() {
        return this;
    }
    
    void          setMatrix( const Matrix& matrix );
    Matrix&       getMatrix();
    const Matrix& getMatrix() const;
    
    virtual void computeBound() const;
    
private:
    Matrix mTransform;
};

#endif // TRANSFORM_H_
