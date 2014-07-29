#include <GL/glut.h>
#include "lecture1.h"
Lecture1 gTheLecture(800);
void timeDisplay(void)
{
	gTheLecture.mTime=gTheLecture.mTime+0.1;

	gTheLecture.mDataX.push_back(gTheLecture.function(gTheLecture.originXFunction(gTheLecture.mOriginTime),gTheLecture.mTime));

    glutPostRedisplay();
}

void MouseFunc(int button,int state,int x,int y)
{
switch(button)
{
case GLUT_LEFT_BUTTON:
if (state==GLUT_DOWN) glutIdleFunc(gTheLecture.mIdleFunc); break;

case GLUT_RIGHT_BUTTON: if (state==GLUT_DOWN) glutIdleFunc(NULL); break;
}
}

void DisplayFunc(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    gTheLecture.drawLines();
    glPopMatrix();
    glutSwapBuffers();
}

Lecture1::Lecture1(int WinSize)
: PBModulingLecture(WinSize)
, mIdleFunc(timeDisplay)
, mOriginX(0.0f)
, mOriginTime(0.0f)
, mX(0.0f)
, mTime(0.0f)
{
	mDisplayFunc = DisplayFunc;
	mMouseFunc = MouseFunc;
}

float Lecture1::originXFunction(float time)
{
	mOriginX = mOriginX + time * time * time;
    return mOriginX;
}

float Lecture1::function(float origin_x,float time)
{
	float h = time - mOriginTime;
	mOriginTime = time;
    return origin_x + h * (3 * time * time) + h*h*6*time/2;
}

void Lecture1::drawLines(void)
{
    glBegin(GL_LINE_STRIP);
    for(int j = 0; j < mDataX.size(); j++)
    {
        float x = (mDataX[j] - 800.0f)/mWinSize;
        float y = (j - 400.0f)/mWinSize;
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
}
    


int main(int argc, char** argv)
{
	gTheLecture.InitGLUT(argc, argv, "PBM Lecture1");
	gTheLecture.Run();
    return 0;
}
