#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>


#include "lecture2.h"

Lecture2 gTheLecture(800);


void timeDisplay(void)
{
	static int onetime=20;
	if (onetime-- > 0)
	{
		Imath::V3f position, velocity, forces;
		float mass;
		position.x = rand()%800*1.0f;
		position.y = rand()%800*1.0f;
		position.z = 0.0f;
		velocity.x = rand()%8000/1.0f;
		velocity.y = rand()%8000/1.0f;
		velocity.z = 0.0f;
		forces.x = 0.0f;//rand()%8/1.0f;
		forces.y = 0.0f;//rand()%8/1.0f;
		forces.z = 0.0f;
		mass = 1.0f;
		//onetime = true;
		gTheLecture.mParticleSystem.AddParticle(position, velocity, forces, mass);
		gettimeofday(&gTheLecture.mTimer, 0);
	}
	//printf("pos x= %f, y= %f, z= %f", coord.mPosition[X], coord.mPosition[Y], coord.mPosition[Z]);
	timeval cur_time;
	gettimeofday(&cur_time, 0);
	float delta_time = 1000000 * (cur_time.tv_sec - gTheLecture.mTimer.tv_sec) + cur_time.tv_usec - gTheLecture.mTimer.tv_usec;
	delta_time /= 1000000;
	gTheLecture.mParticleSystem.EulerStep(delta_time);
	gTheLecture.mTimer = cur_time;
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );  // Clear Color and Depth
	gTheLecture.draw();
    glutSwapBuffers();
}

Lecture2::Lecture2(int WinSize)
: PBModulingLecture(WinSize)
, mIdleFunc(timeDisplay)
{
	mDisplayFunc = DisplayFunc;
	mMouseFunc = MouseFunc;
}

void Lecture2::draw(void)
{
	int num_particles = mParticleSystem.getParticleCount();
	for (int i = 0; i < num_particles; ++i)
	{
		const Imath::V3f& pos = mParticleSystem.getParticlePos(i);

		//printf("pos x= %f, y= %f\n", (pos.x - 800)/800, (pos.y - 400)/800);

		glPushMatrix();			     // Draw Moon
		  //glRotatef( x, 0.0, 1.0, 0.0);	     // Rotate
		  //glTranslatef(-0.5, -0.5, 0.0f);
		  glTranslatef((pos.x - 800)/800, (pos.y - 400)/800, 0.0f);	     // Move reference point
		  glColor3f(0.0,0.0,1.0);		     // Color Blue
		  glutWireSphere(0.1,20,16);	     // Draw Sphere
		glPopMatrix();			  // Return to former reference
	}
}
    


int main(int argc, char** argv)
{
	gTheLecture.InitGLUT(argc, argv, "PBM Lecture1");
	//Imath::V3f dir(0.0f, -1.0f, 0.0f);
	//Gravity* g = new Gravity(9.98f, dir);
	//gTheLecture.mParticleSystem.AddForce(g);
	ViscousDrag* vd = new ViscousDrag(3.0f);
	gTheLecture.mParticleSystem.AddForce(vd);
	gTheLecture.Run();
    return 0;
}
