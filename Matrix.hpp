#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vector.hpp"

// If this option is set, the constructor creates an identity matrix
// If this option is not set, the constructor creates a zero matrix
#define Matrix_Constructor_Identity 1

class Matrix
{
public:
    float _m[9];
    
    Matrix();
    Matrix(const Matrix& rhs);
    Matrix(const Vectorf& col_0, const Vectorf& col_1, const Vectorf& col_2);
    
    static Matrix scale( Vectorf& scale );
    static Matrix translate( Vectorf& trans );
    static Matrix rotate( float degrees );
    static Matrix ident();
    
    float& operator[](const unsigned int& idx);
    const float& operator[](const unsigned int& idx) const;
    
    float& operator()(const unsigned int& col, const unsigned int& row);
    const float& operator()(const unsigned int& col, const unsigned int& row) const;
    
    Matrix& operator=(const Matrix& rhs);
    
    Matrix operator*(const Matrix& rhs) const;
    Matrix& operator*=(const Matrix& rhs);
    
    Vectorf operator*(const Vectorf& rhs) const;
    
    Matrix transpose() const;
    void toTranspose();
};

#endif // MATRIX_H_
