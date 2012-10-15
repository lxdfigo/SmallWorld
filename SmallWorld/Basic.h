#pragma once
#include "SimpleMath/SimpleMath.h"

namespace swd{

//#define TWO_DIMENSION_PHYSICAL_ENGINE
//#define THREE_DIMENSION_PHYSICAL_ENGINE

#ifdef TWO_DIMENSION_PHYSICAL_ENGINE
	typedef Vec2d VecPos;
#else
	typedef Vec3d VecPos;
#endif

	enum SimMask{
		NOMASK = 0,
		NoGravity = 0x01,
		NoCollision = 0x10,
		NoRubForce = 0x100,
		NoResistence = 0x1000
	};

	typedef VecPos AppliedForce;
	typedef VecPos DirectSpeed;

#define NULL 0
}