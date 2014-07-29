#include "ForcesSystem.h"

void IForce::setForcesSystem(ForcesSystem* forces_system) {
	mForcesSystem = forces_system;
}

Gravity::Gravity(float g, Imath::V3f& direction)
: mG(g)
, mDirection(direction)
{
}

void Gravity::ApplyForce() {
	int element_count = mForcesSystem->mForceBuffer.size();
	for (int index = 0; index < element_count; ++index)
	{
		mForcesSystem->mForceBuffer[index] += mForcesSystem->mMassBuffer[index] * mDirection * mG;
	}
}

ViscousDrag::ViscousDrag(float k)
: mK(k)
{}

void ViscousDrag::ApplyForce() {
	int element_count = mForcesSystem->mForceBuffer.size();
	for (int index = 0; index < element_count; ++index)
	{
		mForcesSystem->mForceBuffer[index] += mForcesSystem->mVelocityBuffer[index] * mK * -1;
	}
}

ForcesSystem::ForcesSystem()
{

}

void ForcesSystem::AddForce(IForce* forces) {
	forces->setForcesSystem(this);
	mForces.push_back(forces);
}

void ForcesSystem::CalculateForces() const {
	for (int i = 0; i < mForces.size(); ++i) {
		mForces[i]->ApplyForce();
	}
}
