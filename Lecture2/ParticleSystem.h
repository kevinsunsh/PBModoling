#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <vector>
#include <OpenEXR/ImathVec.h>

#include "Common.h"
#include "ForcesSystem.h"

class ParticleSystem : public ForcesSystem
{
	struct Particle
	{
		int mDataIndex;
	};

	std::vector<Particle*> mParticles; 	/* array of pointers to particles */

	//int mNum; 			/* number of particles */
	float mTime;		/* simulation clock */

	void ClearForces();
	void ComputeForces(ForcesSystem&  forces_sys);
public:
	ParticleSystem();
	~ParticleSystem();
	int getParticleCount() {return mParticles.size();}
	const Imath::V3f& getParticlePos(int index) {return mPositionBuffer[index];}
	void AddParticle(const Imath::V3f& position, const Imath::V3f& velocity, const Imath::V3f& forces, float mass);
	void EulerStep(float DeltaT);
};

#endif // PARTICLESYSTEM_H

