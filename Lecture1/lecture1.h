#include <vector>

#include "Base/base.h"

class Lecture1 : public PBModulingLecture
{
public:
	Lecture1(int WinSize);
	virtual ~Lecture1(){}

	float mOriginX;
	float mOriginTime;
	float mX;
	float mTime;
	enum {
		Euler_Method,
	};

	std::vector<float> mDataX;

	typedef void(*TheIdleFunc)(void);
	TheIdleFunc mIdleFunc;
	float originXFunction(float time);
	float function(float origin_x,float time);
	void drawLines(void);
};


