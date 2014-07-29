#ifndef LECTURE_2_H
#define LECTURE_2_H

#include <vector>
#include <sys/time.h>

#include "Base/base.h"
#include "ParticleSystem.h"
#include "ForcesSystem.h"

class Lecture2 : public PBModulingLecture
{
public:
	Lecture2(int WinSize);
	virtual ~Lecture2(){}

	typedef void(*TheIdleFunc)(void);
	TheIdleFunc mIdleFunc;
	void draw();
	ParticleSystem mParticleSystem;

	timeval mTimer;
};

#endif

