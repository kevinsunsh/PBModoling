
#include "ParticleSystem.h"
#include "ForcesSystem.h"


ParticleSystem::ParticleSystem()
: mTime(0.0f)
{
}

ParticleSystem::~ParticleSystem()
{
	for(int i=0; i < mParticles.size(); i++)
	{
		delete mParticles[i];
	}

	mParticles.clear();
}

void ParticleSystem::ClearForces()
{
	for(int i=0; i < mParticles.size(); i++)
	{
		mForceBuffer[i] = Imath::V3f(0.0f, 0.0f, 0.0f);
	}
}

void ParticleSystem::AddParticle(const Imath::V3f& position, const Imath::V3f& velocity, const Imath::V3f& forces, float mass)
{
	Particle* new_p = new Particle();
	new_p->mDataIndex = mParticles.size();
	mPositionBuffer.push_back(position);
	mVelocityBuffer.push_back(velocity);
	mForceBuffer.push_back(forces);
	mMassBuffer.push_back(mass);
	mParticles.push_back(new_p);
}

void ParticleSystem::EulerStep(float DeltaT)
{
	/* zero the force accumulators */
	ClearForces();
	/* magic force function */
	CalculateForces();

	for(int i=0; i < mParticles.size(); i++)
	{
		mPositionBuffer[i] += mVelocityBuffer[i] * DeltaT;
		mVelocityBuffer[i] += mForceBuffer[i]/mMassBuffer[i] * DeltaT;

		//printf("pos x= %f, y= %f, time = %f\n", mVelocityBuffer[i].x, mVelocityBuffer[i].y, mTime);
	}

	/* update time */
	mTime += DeltaT;
}

