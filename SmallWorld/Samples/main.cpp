#include "stdio.h"
#include "../SmallWorld.h"

using namespace swd;

class Role : public RigidObj{
public:
	Role(VecPos v1,VecPos v2):RigidObj(v1,v2){}
	~Role(){}

	virtual void callbackCollision(Collision *col){}
};
int main(){
	Role body(VecPos(),VecPos(2));
	return 0;
}