#ifndef MATHUTIL_H_
#define MATHUTIL_H_

#include <cmath>

template<typename Real>
inline Real DegToRad(const Real& degrees)
{
    return static_cast<Real>((M_PI / 180.0)) * degrees;
}

template<typename Real>
inline Real RadToDeg(const Real& radians)
{
    return static_cast<Real>((180.0 / M_PI)) * radians;
}

template<typename T>
inline const T& min(const T& l, const T& r)
{
    if(l<r) {
        return l;
    }

    return r;
}

template<typename T>
inline const T& max(const T& l, const T& r)
{
    if(l<r) {
        return r;
    }
    
    return l;
}

template<typename T>
inline const T& clamp(const T& value, const T& min, const T& max)
{
    if(value>max) {
        return max;
    }
    
    if(value<min) {
        return min;
    }
    
    return value;
}

template<typename T>
inline const T& index(const T& x, const T& y, const T& width)
{
    return x + y * width;
}

template<typename T>
inline void unindex(const T& index, const T& width, const T& height, T& x, T& y)
{
    x = index % width;
    y = (T)floor((double)(index / height));
}

#endif // MATHUTIL_H_
