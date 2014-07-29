#include <string>
#include <GL/glut.h>

#include "base.h"

void ReshapeFunc(int w, int h) {
	glViewport(0, 0, (GLsizei) (w), (GLsizei) (h));
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

PBModulingLecture::PBModulingLecture(int WinSize)
: mDisplayFunc(0)
, mReshapeFunc(ReshapeFunc)
, mMouseFunc(0)
, mWinSize(WinSize)
{
}

void PBModulingLecture::InitGLUT(int argc, char** argv, const char* title)
{
    // GLUT Window Initialization:
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(mWinSize,mWinSize);
    glutInitWindowPosition(100,100);
    glutCreateWindow (title);
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);
}



inline void PBModulingLecture::Run(void) {
	glutDisplayFunc (mDisplayFunc);
	glutReshapeFunc (mReshapeFunc);
	glutMouseFunc (mMouseFunc);
	glutMainLoop();
}


 
