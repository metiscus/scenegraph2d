#ifndef VECTOR_H_
#define VECTOR_H_

template<typename Real>
class Vector
{
public:
    Real x, y;
    
    Vector();
    Vector(const Real& _x, const Real& _y);
    Vector(const Vector& rhs);
        
    inline Vector& operator=(const Vector& rhs);
    
    template<typename T>
    inline Vector<Real>& operator=(const Vector<T>& rhs);
    
    inline Vector operator+(const Vector& rhs) const;
    inline Vector operator-(const Vector& rhs) const;
    
    template<typename T>
    inline Vector operator*(const T& rhs) const;
    
    template<typename T>
    inline Vector operator/(const T& rhs) const;
    
    inline Vector& operator+=(const Vector& rhs);
    inline Vector& operator-=(const Vector& rhs);
    
    template<typename T>
    inline Vector& operator*=(const T& rhs);
    
    template<typename T>
    inline Vector& operator/=(const T& rhs);    
    
    Real dot(const Vector& rhs) const;
    
    Real length() const;
    Real length2() const;
    
    Vector asUnit() const;
    Real   toUnit();
};

template<typename Real>
inline Vector<Real> operator*( const Real& lhs, const Vector<Real>& rhs )
{
    return rhs * lhs;
}

template<typename Real>
Vector<Real>::Vector()
{
    x = static_cast<Real>(0);
    y = static_cast<Real>(0);
}

template<typename Real>
Vector<Real>::Vector(const Real& _x, const Real& _y)
{
    x = static_cast<Real>(_x);
    y = static_cast<Real>(_y);
}

template<typename Real>
Vector<Real>::Vector(const Vector& rhs)
{
    x = static_cast<Real>(rhs.x);
    y = static_cast<Real>(rhs.y);
}

template<typename Real>
Vector<Real>& Vector<Real>::operator=(const Vector& rhs)
{
    x = rhs.x;
    y = rhs.y;
    return *this;
}

template<typename Real>
template<typename T>
Vector<Real>& Vector<Real>::operator=(const Vector<T>& rhs)
{
    x = static_cast<Real>(rhs.x);
    y = static_cast<Real>(rhs.y);
    return *this; 
}

template<typename Real>
Vector<Real> Vector<Real>::operator+(const Vector& rhs) const
{
    return Vector<Real>(static_cast<Real>(rhs.x) + x, static_cast<Real>(rhs.y) + y);
}

template<typename Real>
Vector<Real> Vector<Real>::operator-(const Vector& rhs) const
{
    return Vector<Real>(x - static_cast<Real>(rhs.x), y - static_cast<Real>(rhs.y));
}

template<typename Real>
template<typename T>
Vector<Real> Vector<Real>::operator*(const T& rhs) const
{
    return Vector<Real>(x * static_cast<Real>(rhs), y * static_cast<Real>(rhs));
}

template<typename Real>
template<typename T>
Vector<Real> Vector<Real>::operator/(const T& rhs) const
{
    Real invRhs = static_cast<Real>(1.)/ static_cast<Real>(rhs);
    return Vector<Real>(x * invRhs, y * invRhs);
}

template<typename Real>
Vector<Real>& Vector<Real>::operator+=(const Vector& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

template<typename Real>
Vector<Real>& Vector<Real>::operator-=(const Vector& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;    
}

template<typename Real>
template<typename T>
Vector<Real>& Vector<Real>::operator*=(const T& rhs)
{
    x *= static_cast<Real>(rhs);
    y *= static_cast<Real>(rhs);
    return *this;
}

template<typename Real>
template<typename T>
Vector<Real>& Vector<Real>::operator/=(const T& rhs)
{
    Real invRhs = static_cast<Real>(1.)/ static_cast<Real>(rhs);    
    x *= invRhs;
    y *= invRhs;
    return *this;
}

template<typename Real>
Real Vector<Real>::dot(const Vector& rhs) const
{
    return Vector<Real>(x*rhs.x + y*rhs.y);
}

template<typename Real>
Real Vector<Real>::length() const
{
    return sqrt(x*x+y*y);
}

template<typename Real>
Real Vector<Real>::length2() const
{
    return x*x + y*y;
}

template<typename Real>
Vector<Real> Vector<Real>::asUnit() const
{
    Real invMag = static_cast<Real>(static_cast<Real>(1) / sqrt(x*x+y*y));
    return Vector<Real>( x * invMag, y * invMag );
}

template<typename Real>
Real Vector<Real>::toUnit()
{
    Real mag = static_cast<Real>(sqrt(x*x+y*y));
    Real invMag = static_cast<Real>(1) / mag;
    x *= invMag;
    y *= invMag;
    return mag;
}

typedef Vector<float> Vectorf;
typedef Vector<int> Vectori;

#endif // VECTOR_H_
