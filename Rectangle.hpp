#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Vector.hpp"
#include "MathUtil.hpp"

class Rectangle
{
public:
    Rectangle();
    Rectangle(const Vectorf& min, const Vectorf& max);
    Rectangle(const Rectangle& rhs);
    
    void reset();
    void expandBy(const Rectangle& rhs);
    
    bool contains(const Rectangle& rhs) const;
    bool contains(const Vectorf& rhs) const;
    
    float getWidth() const;
    float getHeight() const;
    Vectorf getMin() const;
    Vectorf getMax() const;
    Vectorf getCenter() const;
    
    void setMin( const Vectorf& min );
    void setMax( const Vectorf& max );
    void set( const Vectorf& min, const Vectorf& max );
    void set( float x, float y, float w, float h );

    Rectangle& operator=(const Rectangle& rhs);

private:
    Vectorf mMin;
    Vectorf mMax;
};

#endif // RECTANGLE_H_
