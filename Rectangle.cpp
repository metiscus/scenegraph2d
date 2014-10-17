#include "Rectangle.hpp"

Rectangle::Rectangle()
{
    ;
}

Rectangle::Rectangle(const Vectorf& min, const Vectorf& max)
{
    mMin = min;
    mMax = max;
}

Rectangle::Rectangle(const Rectangle& rhs)
{
    mMin = rhs.mMin;
    mMax = rhs.mMax;
}

void Rectangle::reset()
{
    mMin.x = mMin.y = 0;
    mMax.x = mMax.y = 0;
}

void Rectangle::expandBy(const Rectangle& rhs)
{
    mMin.x = min(mMin.x, rhs.mMin.x);
    mMin.y = min(mMin.y, rhs.mMin.y);
    mMax.x = max(mMax.x, rhs.mMax.x);
    mMax.y = max(mMax.y, rhs.mMax.y);
}

bool Rectangle::contains(const Rectangle& rhs) const
{
    Vectorf ll(rhs.mMin);
    Vectorf lr(rhs.mMax.x, rhs.mMin.y);
    Vectorf ul(rhs.mMin.x, rhs.mMax.y);
    Vectorf ur(rhs.mMax);
    return contains(ll) && contains(lr) && contains(ul) && contains(ur);
}

bool Rectangle::contains(const Vectorf& rhs) const
{
    return (rhs.x >= mMin.x && rhs.x <= mMax.x) &&
           (rhs.y >= mMin.y && rhs.y <= mMax.y);
}

float Rectangle::getWidth() const
{
    return mMax.x - mMin.x;
}

float Rectangle::getHeight() const
{
    return mMax.y - mMin.y;
}

Vectorf Rectangle::getMin() const
{
    return mMin;
}

Vectorf Rectangle::getMax() const
{
    return mMax;
}

Vectorf Rectangle::getCenter() const
{
    return 0.5f * (mMax + mMin);
}

void Rectangle::setMin( const Vectorf& min )
{
    mMin = min;
}

void Rectangle::setMax( const Vectorf& max )
{
    mMax = max;
}

void Rectangle::set( const Vectorf& min, const Vectorf& max )
{
    mMin = min;
    mMax = max;
}
void Rectangle::set( float x, float y, float w, float h )
{
    mMin = Vectorf( x - w / 2, y - h / 2);
    mMax = Vectorf( x + w / 2, y + h / 2);
}

Rectangle& Rectangle::operator=(const Rectangle& rhs)
{
    mMin = rhs.mMin;
    mMax = rhs.mMax;
    return *this;
}
