#include "PolyBody.h"

using namespace swd;

void PolyBody::transform(Transform & trans){
	//for(unsigned i = 0; i < polygon.size(); ++i){
	//	polygon.setPos(i,trans.trans(polygon.pos(i)));
	//}
}

bool PolyBody::checkBoxCross(Body*obj,CollideInfo *col){
	return false;
}
bool PolyBody::checkPolygonCross(Body*obj,CollideInfo *col){
	return false;
}