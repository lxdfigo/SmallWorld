#include "BoxBody.h"

using namespace swd;


void BoxBody::advance(Timer &timer){
	lastBox = box;
	VecPos mv = speed * timer.step();
	transform(Transform().makeMoveTrans(mv));
	speed += appliedForce / mass * timer.step();
	appliedForce.zero();
	isMoved = true;
}

void BoxBody::transform(Transform & trans){
	box.reset(trans.trans(box.getBegin()),trans.trans(box.getEnd()));
}


VecPos BoxBody::sloveLineCrossAABB(AABB &aabb,Line &line,VecPos &vec){
	//////////////////////////////////////////////////////////////
	//
	//                _____________
	//              / |            |
	//             /  |            |
	//            /   |          \ |
	//                |___________\|
	//
	//
	//////////////////////////////////////////////////////////////


	VecPos moveVec;
	if (aabb.solveLine(line)){
		moveVec = line.getVec();
		double distance = moveVec.Length2();
		for(int i = 0;i < DIMENSION; ++i){
			if (line.begin[i] < line.end[i]){
				VecPos tvec = line.end - line.getPos(i,vec[i]);
				double tmpdistance = tvec.Length2();
				if (tmpdistance < distance){
					moveVec = tvec;
					distance = tmpdistance;
				}
			}
		}
	}
	return moveVec;
}
void BoxBody::attack(Body *body){
	//Update Speed of the two Collision Entitys
	DirectSpeed v1 = getSpeed();
	DirectSpeed v2 = body->getSpeed();
	double m1 = getMass();
	double m2 = body->getMass();
	setSpeed((v1 * (m1 - m2) + 2 * m2 * v2) / (m1 + m2));
}

bool BoxBody::checkBoxCross(Body*body,Collision *col){
	return true;
}
bool BoxBody::solveBox(Body*body,Collision *col){
	if (!isMoved) return true;
	isMoved = false;
	Line beginLine(box.getBegin(),lastBox.getBegin());
	Line endLine(box.getEnd(),lastBox.getEnd());

	VecPos moveVecb = sloveLineCrossAABB(body->getAABB(),beginLine,lastBox.getEnd());
	VecPos moveVece = sloveLineCrossAABB(body->getAABB(),endLine,lastBox.getBegin());
	if (moveVece.Length2() < moveVecb.Length2()){
		transform(Transform().makeMoveTrans(moveVece));
	}else{
		transform(Transform().makeMoveTrans(moveVecb));
	}
	return false;
}
bool BoxBody::checkPolygonCross(Body*body,Collision *col){
	return false;
}
bool BoxBody::solvePolygon(Body*body,Collision *col){
	return false;
}