#ifndef PBMODULINGLECTURE_H
#define PBMODULINGLECTURE_H
#include <string>

class PBModulingLecture
{
public:
	PBModulingLecture(int WinSize);
	virtual ~PBModulingLecture() {}
	void InitGLUT(int argc, char** argv, const char* title);
	virtual void Run(void);
protected:

	int mWinSize;
	typedef void(*TheDisplayFunc)(void);
	TheDisplayFunc mDisplayFunc;

	typedef void(*TheReshapeFunc)(int w, int h);
	TheReshapeFunc mReshapeFunc;

	typedef void(*TheMouseFunc)(int button,int state,int x,int y);
	TheMouseFunc mMouseFunc;
};

#endif
