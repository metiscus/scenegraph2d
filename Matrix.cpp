#include <cmath>

#include "MathUtil.hpp"
#include "Matrix.hpp"

Matrix::Matrix()
{
#if Matrix_Constructor_Identity
    _m[0] = 1; _m[1] = 0; _m[2] = 0;
    _m[3] = 0; _m[4] = 1; _m[5] = 0;
    _m[6] = 0; _m[7] = 0; _m[8] = 1;
#else 
    _m[0] = 0; _m[1] = 0; _m[2] = 0;
    _m[3] = 0; _m[4] = 0; _m[5] = 0;
    _m[6] = 0; _m[7] = 0; _m[8] = 0;
#endif    
}

Matrix::Matrix(const Matrix& rhs)
{
    _m[0] = rhs._m[0]; _m[1] = rhs._m[1]; _m[2] = rhs._m[2];
    _m[3] = rhs._m[3]; _m[4] = rhs._m[4]; _m[5] = rhs._m[5];
    _m[6] = rhs._m[6]; _m[7] = rhs._m[7]; _m[8] = rhs._m[8];
}

Matrix::Matrix(const Vectorf& col_0, const Vectorf& col_1, const Vectorf& col_2)
{
    _m[0] = col_0.x; _m[1] = col_1.x; _m[2] = col_2.x;
    _m[3] = col_0.y; _m[4] = col_1.y; _m[5] = col_2.y;
    _m[6] = 0;       _m[7] = 0;       _m[8] = 1;    
}

Matrix Matrix::scale( Vectorf& scale )
{
    Matrix newMat;
    newMat._m[0] = scale.x; newMat._m[1] = 0; newMat._m[2] = 0;
    newMat._m[3] = 0; newMat._m[4] = scale.y; newMat._m[5] = 0;
    newMat._m[6] = 0; newMat._m[7] = 0; newMat._m[8] = 1;
    return newMat;
}

Matrix Matrix::translate( Vectorf& trans )
{
    Matrix newMat;
    newMat._m[0] = 1; newMat._m[1] = 0; newMat._m[2] = trans.x;
    newMat._m[3] = 0; newMat._m[4] = 1; newMat._m[5] = trans.y;
    newMat._m[6] = 0; newMat._m[7] = 0; newMat._m[8] = 1;
    return newMat;
}

Matrix Matrix::rotate( float degrees )
{
    Matrix newMat;
    float radians = DegToRad(degrees);
    float cRad = cosf(radians);
    float sRad = sinf(radians);
    newMat._m[0] = cRad; newMat._m[1] = -sRad; newMat._m[2] = 0;
    newMat._m[3] = sRad; newMat._m[4] = cRad; newMat._m[5] = 0;
    newMat._m[6] = 0; newMat._m[7] = 0; newMat._m[8] = 1;
    return newMat;
}

Matrix Matrix::ident()
{
#if Matrix_Constructor_Identity
    return Matrix();
#else
    Matrix newMat;
    newMat._m[0] = 1; newMat._m[1] = 0; newMat._m[2] = 0;
    newMat._m[3] = 0; newMat._m[4] = 1; newMat._m[5] = 0;
    newMat._m[6] = 0; newMat._m[7] = 0; newMat._m[8] = 1;
    return newMat;
#endif
}

float& Matrix::operator[](const unsigned int& idx)
{
    return _m[idx];
}

const float& Matrix::operator[](const unsigned int& idx) const
{
    return _m[idx];
}

float& Matrix::operator()(const unsigned int& col, const unsigned int& row)
{
    return _m[col * 3 + row];
}

const float& Matrix::operator()(const unsigned int& col, const unsigned int& row) const
{
    return _m[col * 3 + row];
}

Matrix& Matrix::operator=(const Matrix& rhs)
{
    _m[0] = rhs._m[0]; _m[1] = rhs._m[1]; _m[2] = rhs._m[2];
    _m[3] = rhs._m[3]; _m[4] = rhs._m[4]; _m[5] = rhs._m[5];
    _m[6] = rhs._m[6]; _m[7] = rhs._m[7]; _m[8] = rhs._m[8];
    return *this;
}

Matrix Matrix::operator*(const Matrix& rhs) const
{
    Matrix newMat;
    newMat._m[0] = _m[0]*rhs[0] + _m[1]*rhs[3] + _m[2]*rhs[6];
    newMat._m[1] = _m[0]*rhs[1] + _m[1]*rhs[4] + _m[2]*rhs[7];
    newMat._m[2] = _m[0]*rhs[2] + _m[1]*rhs[5] + _m[2]*rhs[8];

    newMat._m[3] = _m[3]*rhs[0] + _m[4]*rhs[3] + _m[5]*rhs[6];
    newMat._m[4] = _m[3]*rhs[1] + _m[4]*rhs[4] + _m[5]*rhs[7];
    newMat._m[5] = _m[3]*rhs[2] + _m[4]*rhs[5] + _m[5]*rhs[8];
    
    newMat._m[6] = _m[6]*rhs[0] + _m[7]*rhs[3] + _m[8]*rhs[6];
    newMat._m[7] = _m[6]*rhs[1] + _m[7]*rhs[4] + _m[8]*rhs[7];
    newMat._m[8] = _m[6]*rhs[2] + _m[7]*rhs[5] + _m[8]*rhs[8];
    return newMat;  
}

Matrix& Matrix::operator*=(const Matrix& rhs)
{
    Matrix newMat;
    newMat._m[0] = _m[0]*rhs[0] + _m[1]*rhs[3] + _m[2]*rhs[6];
    newMat._m[1] = _m[0]*rhs[1] + _m[1]*rhs[4] + _m[2]*rhs[7];
    newMat._m[2] = _m[0]*rhs[2] + _m[1]*rhs[5] + _m[2]*rhs[8];

    newMat._m[3] = _m[3]*rhs[0] + _m[4]*rhs[3] + _m[5]*rhs[6];
    newMat._m[4] = _m[3]*rhs[1] + _m[4]*rhs[4] + _m[5]*rhs[7];
    newMat._m[5] = _m[3]*rhs[2] + _m[4]*rhs[5] + _m[5]*rhs[8];
    
    newMat._m[6] = _m[6]*rhs[0] + _m[7]*rhs[3] + _m[8]*rhs[6];
    newMat._m[7] = _m[6]*rhs[1] + _m[7]*rhs[4] + _m[8]*rhs[7];
    newMat._m[8] = _m[6]*rhs[2] + _m[7]*rhs[5] + _m[8]*rhs[8];
    *this = newMat;
    return *this;     
}

Vectorf Matrix::operator*(const Vectorf& rhs) const
{
    return Vectorf( _m[0]*rhs.x + _m[1]*rhs.y + _m[2],
                    _m[3]*rhs.x + _m[4]*rhs.y + _m[5] );
}

Matrix Matrix::transpose() const
{
    Matrix newMat;
    for(int y=0; y<3; ++y)
    {
        for(int x=0; x<3; ++x)
        {
            newMat[8-(x-y*3)] = _m[y*3+x];
        }
    }
    return newMat;
}

void Matrix::toTranspose()
{
    Matrix newMat;
    for(int y=0; y<3; ++y)
    {
        for(int x=0; x<3; ++x)
        {
            newMat[8-(x-y*3)] = _m[y*3+x];
        }
    }
    *this = newMat;
}
