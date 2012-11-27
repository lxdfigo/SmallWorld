#pragma once
#include "Body.h"
#include "Deactivator.h"
#include "Status.h"

namespace swd{
	class Action;
	class Constraint;

	class Entity
	{
	public:
		Entity(SWID id = ""):simMask(NOMASK),oID(id),body(NULL){}
		virtual ~Entity(void){
			if (body != NULL) delete body;
		}
		virtual bool operator != (Entity& entity) const{
			return oID.compare(entity.getID()) != 0;
		}

		// deal with actions
		virtual void applyActions();
		virtual bool addAction(Action *action);
		virtual bool removeAction(Action *action);
		//deal with constraints
		virtual void applyConstraints();
		virtual bool addConstraint(Constraint *constraint);
		virtual bool removeConstraint(Constraint *constraint);

		virtual void setStep(Timer &timer) = 0;
		virtual bool update() = 0;
		virtual bool integrate() = 0;
		virtual void transform(Transform& trans) = 0;
		virtual AABB getAABB() = 0;
		virtual void addForce(AppliedForce force) = 0;
		virtual void addForceOnPoint(AppliedForce force,VecPos point) = 0;
		virtual bool isCrossSingleEntity(Entity *entity,CollideInfo *col) = 0;
		virtual void computeInertia() = 0;

		virtual bool isCross(Entity *entity,CollideInfo *col){ 
			return entity->isCrossSingleEntity(this,col);
		}

		//property functions
		virtual Body *getBody(){return body;}
		virtual VecPos getCentroid(){return centroid;}
		virtual double getMass(){return mass;}
		virtual MomentInertia getMomentInertia(){return inertia;} 
		virtual DirectSpeed getDirectSpeed(){return dirSpeed;}
		virtual AngleSpeed getAngleSpeed(){return angSpeed;}
		virtual SWID getID(){return oID;}
		virtual bool isMask(int mask){ return (mask & simMask) != NOMASK;} 
		virtual void setMask(int mask){simMask |= mask;}

		virtual bool isDisable(){return deactivator.isDisable();}

		virtual void setMass(double ma){mass = ma;}
		virtual void setFriction(double fric){friction_coef = fric;}

	protected:
		SWID oID;
		int simMask;
		Body *body;

		double mass;
		double friction_coef;

		VecPos centroid;
		MomentInertia inertia;

		VecPos position;
		Attitude attitude;
		DirectSpeed dirSpeed;
		AngleSpeed angSpeed;

		Moment moment;
		AppliedForce force;

		std::vector<Action*> actions;
		std::vector<Constraint*> constraints;
		Deactivator deactivator;

		Status status;
	};
}