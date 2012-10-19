#ifndef __MATRIX_H
#define __MATRIX_H
#include "vector.h"

template<class T, int DIMENSION>
class CMatrix
{
public:
	CVector<T,DIMENSION> Rows[DIMENSION];

	CMatrix(){}


	inline CVector<T,DIMENSION> & operator [] (int i) { return Rows[i]; }
	inline CVector<T,DIMENSION>   operator [] (int i) const { return Rows[i]; }
};

typedef CMatrix<float,2> Mat2x2f;
typedef CMatrix<float,3> Mat3x3f;
typedef CMatrix<float,4> Mat4x4f;
typedef CMatrix<double,3> Mat3x3d;
typedef CMatrix<double,4> Mat4x4d;

class Transform{
	Mat4x4d mat;
public:
	Transform(Vec2d vec){}
	Vec2d& trans(Vec2d&  vec){return vec;}

	Transform(Vec3d vec){}
	Vec3d& trans(Vec3d&  vec){return vec;}
};
#endif