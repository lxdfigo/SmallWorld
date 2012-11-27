#pragma once
#include "SimpleMath/SimpleMath.h"
#include <string>
#include <map>
#include <vector>

namespace swd{

//#define TWO_DIMENSION_PHYSICAL_ENGINE
#define THREE_DIMENSION_PHYSICAL_ENGINE

#ifdef TWO_DIMENSION_PHYSICAL_ENGINE
	static const unsigned DIMENSION = 2;
	typedef Vec2d VecPos;
	typedef Trans3x3d Transform;
	typedef double MomentInertia;
	typedef double Attitude;
	typedef double AngleSpeed;
#else
	static const unsigned DIMENSION = 3;
	typedef Vec3d VecPos;
	typedef Trans4x4d Transform;
	typedef Mat3x3d MomentInertia;
	typedef VecPos Attitude;
	typedef VecPos AngleSpeed;
#endif

#define MAXNUM 1E20
#define MINNUM -1E20
#define TINYNUM 1E-5
#define MINUSTINYNUM -1E-5
const static int POWER_2_DIMENSION = 1 << DIMENSION;
	enum SimMask{
		NOMASK = 0,
		NoGravity = 0x01,
		NoCollision = 0x10,
		NoRubForce = 0x100,
		NoResistence = 0x1000,
		STATIC = 0x10000
	};

	typedef VecPos AppliedForce;
	typedef VecPos DirectSpeed;
	typedef VecPos Plan;
	typedef VecPos Moment;
	typedef std::string SWID;

	inline bool g_isZero(double tmp){ 
		if (tmp <= TINYNUM && tmp >= MINUSTINYNUM)
			return true; 
		return false;
	}
#define NULL 0
}