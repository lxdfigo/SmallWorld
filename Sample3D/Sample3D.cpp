// Sample3D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<gl/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include<wingdi.h>
#include <gl/glut.h>
#include<gl/glaux.h>	
#pragma comment(lib, "glew32.lib")
#pragma   comment(   lib,   "glaux.lib ")

float eye[3] = {0, 0, 0};
void Kongjian()
{					
	glMatrixMode(GL_PROJECTION);						
	glLoadIdentity();
	gluPerspective(45,400/400,1,10);							
}
void guangzhao() 
{ 
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	float huanjin[]={0.3,0.3,0.3,1};
	float sanshe[]={0.7,0.7,0.7,1};
	float weizhi[]={1,1,1,0};
	float jinmian[]={1,1,1,1};
	float fanshelv[]={1,1,1,1};
	glLightfv(GL_LIGHT0,GL_POSITION,weizhi);
	glLightfv(GL_LIGHT0,GL_AMBIENT,huanjin);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,sanshe);
	glLightfv(GL_LIGHT0,GL_SPECULAR,jinmian);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT,GL_SPECULAR,fanshelv);
	glMateriali(GL_FRONT,GL_SHININESS,120);
}
void key(unsigned char k, int x, int y)
{
	switch(k)
	{
	case 'a': {
		eye[0]+=1;
		break;
			  }
	case 'd': {
		eye[0]-=1;
		break;
			  }
	case 'w': {
		eye[1]-=1;
		break;
			  }
	case 's': {
		eye[1]+=1;
		break;
			  }
	case 'q':
		{
			eye[2]=eye[2]+1;break;
		}
	case 'e':
		{
			eye[2]=eye[2]-1;break;
		}
	}
}

void redraw()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2],0, 0, -100,0, 1, 0);
	guangzhao() ;

	glTranslated(0,0,-9);
	glColor3f(0.5,0.5,0.5);
	glutSolidTeapot(1);
	glutSwapBuffers();
}
void idle()
{
	glutPostRedisplay();//达到循环的效果
}

int main (int argc,  char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(400,400);
	int windowHandle = glutCreateWindow("键盘控制视角变换");
	Kongjian();
	glutDisplayFunc(redraw);	
	glutKeyboardFunc(key);
	glutIdleFunc(idle);

	glutMainLoop();
	return 0;
}