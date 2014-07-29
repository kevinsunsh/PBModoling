#ifndef FORCESSYSTEM_H
#define FORCESSYSTEM_H

#include <vector>
#include <OpenEXR/ImathVec.h>
#include "Common.h"

class ForcesSystem;

class IForce
{
protected:
	ForcesSystem* mForcesSystem;
public:
	IForce(): mForcesSystem(0){}
	virtual ~IForce(){}
	virtual void ApplyForce() = 0;

	void setForcesSystem(ForcesSystem* forces_system);
};

class UnaryForce : public IForce
{
public:
	UnaryForce(): IForce() {}
};

class NaryForces : public IForce
{
public:
	NaryForces(): IForce() {}
};

//Forces of spatial interaction
class SIForces : public IForce
{
public:
	SIForces(): IForce() {}
};

class Gravity : public UnaryForce
{
	float mG;
	Imath::V3f mDirection;
public:
	Gravity(float g, Imath::V3f& direction);

	virtual void ApplyForce();
};

class ViscousDrag : public UnaryForce
{
	float mK;
public:
	ViscousDrag(float k);

	virtual void ApplyForce();
};

class ForcesSystem
{
	friend class Gravity;
	friend class ViscousDrag;

	std::vector<IForce*> mForces;

protected:
	std::vector<Imath::V3f> mPositionBuffer;
	std::vector<Imath::V3f> mVelocityBuffer;
	std::vector<Imath::V3f> mForceBuffer;
	std::vector<float> mMassBuffer;
public:
	ForcesSystem();

	void CalculateForces() const;
	void AddForce(IForce* forces);
};



#endif // FORCESSYSTEM_H

