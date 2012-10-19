#pragma once
#include "SimpleMath/SimpleMath.h"
#include <string>
#include <map>
#include <vector>

namespace swd{

#define TWO_DIMENSION_PHYSICAL_ENGINE
//#define THREE_DIMENSION_PHYSICAL_ENGINE

#ifdef TWO_DIMENSION_PHYSICAL_ENGINE
	static const unsigned DIMENSION = 2;
	typedef Vec2d VecPos;
#else
	static const unsigned DIMENSION = 3;
	typedef Vec3d VecPos;
#endif

#define MAXNUM 1E20
#define MINNUM -1E20

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
	typedef std::string SWID;

#define NULL 0
}