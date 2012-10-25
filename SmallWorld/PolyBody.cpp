#include "PolyBody.h"

using namespace swd;

void PolyBody::advance(Timer &timer){

}

void PolyBody::transform(Transform & trans){
	for(unsigned i = 0; i < polygon.size(); ++i){
		for(unsigned j = 0; j < DIMENSION; ++j){
			polygon[i][j] = trans.trans(polygon[i][j]);
		}
	}
}

bool PolyBody::checkBoxCross(Body*obj,Collision *col){
	return false;
}
bool PolyBody::checkPolygonCross(Body*obj,Collision *col){
	return false;
}
bool PolyBody::solveBox(Body*obj,Collision *col){
	return false;
}
bool PolyBody::solvePolygon(Body*obj,Collision *col){
	return false;
}