#include "BoxBody.h"

using namespace swd;


MomentInertia BoxBody::getInertia(){
	double Ixx,Iyy,Izz,Ixz,Iyz,Ixy;
	MomentInertia moment;
	double lens[DIMENSION];
	for(int i = 0; i < DIMENSION; ++i){
		lens[i] = box.end[i] - box.begin[i];
	}
	Ixx = (lens[1] * lens[1] + lens[2] * lens[2]) / 12;
	Iyy = (lens[0] * lens[0] + lens[2] * lens[2]) / 12;
	Izz = (lens[1] * lens[1] + lens[0] * lens[0]) / 12;
	return moment;
}

void BoxBody::transform(Transform & trans){
	box.reset(trans.trans(box.begin),trans.trans(box.end));
}


bool BoxBody::checkBoxCross(Body*body,CollideInfo *col){
	//the compare is finished before for they all the AABB Box 
	return true;
}
//bool BoxBody::solveBox(Body*body,CollideInfo *col){
//
//	Step One: step back, solve the collision
//	AABB &aabb = body->getAABB();
//	VecPos begins[POWER_2_DIMENSION];
//	VecPos ends[POWER_2_DIMENSION];
//	box.getVexs(begins);
//	lastBox.getVexs(ends);
//
//	for(int i = 0; i < POWER_2_DIMENSION; ++i){
//		Line line(begins[i],ends[i]);
//		if (aabb.solveLine(line)){
//			if (line.Length2() > backline.Length2()){
//				backline = line;
//				
//				int plan = backline.LongestDimension();//aabb.getCrossPlan(box);
//				if (plan >= 0 && tmpSpeed[plan] != 0){
//					collisions[curCollision].plan = plan;
//					collisions[curCollision].mass = body->getMass();
//					DirectSpeed &sp = body->getSpeed();
//					collisions[curCollision].speed = sp[plan];
//				}
//			}
//		}
//	}
//
//	return true;
//}
bool BoxBody::checkPolygonCross(Body*body,CollideInfo *col){
	return false;
}