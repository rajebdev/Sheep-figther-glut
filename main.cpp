#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <math.h>
#include "Sheep.h"

using namespace std;

// Rotation
float rotX=0, rotY=0, rotZ=0;
float tempRotX=0, tempRotY=0, tempRotZ=0;

// Mouse Gerak
float angle = 0.0f;
float lx=0.0f,lz=-1.0f;
float x=0.0f, z=5.0f;
float deltaAngle = 0.0f;
int xOrigin = -1;

int model = 0;

// Cameras
int viewMode = 1;
float pos[] = {2,10.5,1.5};
float viewDir[] = {0,-1,0};
float alpha = 5;

// Transparant Objek
float alphaTrans = 1;


void setMaterialColor(float r, float g, float b, float a)
{
    GLfloat mat_specular[] = {r, g, b, a };
    GLfloat mat_shininess[] = { 10.0f };
    GLfloat mat_diffuse[] = {r, g, b, a };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
}

#include "Objek.h"

void setView()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(viewMode == 2) {
        gluPerspective(90.0,1,1,200);
        gluLookAt(pos[0],pos[1],pos[2]+0.5,pos[0]+viewDir[0],pos[1]+viewDir[1],pos[2]+viewDir[2],0,0,1);
    }
    else{
        glOrtho (-105, 105, -140, 140, -1000.0, 1000.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void setModel(){
    if (model == 1)
    {
        sheep1();
    }
    else if (model == 2)
    {
        sheep2();
    }
    else if (model == 3)
    {
        sheep3();
    }
    else if (model == 4)
    {
        sheep4();
    }
    else if (model == 5)
    {
        sheep1();
    }
    else if (model == 6)
    {
        sheep2();
    }
    else if (model == 7)
    {
        sheep3();
    }
    else if (model == 8)
    {
        sheep4();
    }
    else if (model == 9)
    {
        ayam();
    }
}

void display()
{
    setView();
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    gluLookAt(	x, 1.0f, z,
			x+lx, 1.0f,  z+lz,
			0.0f, 1.0f,  0.0f);

    setMaterialColor(7, 7, 7, alphaTrans);

    glRotated(rotX, 1, 0, 0);
    glRotated(rotY, 0, 1, 0);
    glRotated(rotZ, 0, 0, 1);

    setModel();

    createBackground();

    glutSwapBuffers();
}

#include "Input.h"


void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-105, 105, -140*(GLfloat)h/(GLfloat)w, 140*(GLfloat)h/(GLfloat)w, -100.0, 100.0);
    else
        glOrtho (-105*(GLfloat)w/(GLfloat)h, 105*(GLfloat)w/(GLfloat)h, -140, 140, -100.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void myinit()
{
    glClearColor (0, 0.8, 1, 1);
    // lighting
    GLfloat light_position_diff[] = { 10.0, 10.0, 5.0, 0.0};
    GLfloat light_position_spec[] = { 10.0, -10.0, 5.0, 0.0 };
    GLfloat diffuse_light[] = { 0.8, 0.8, 1.0, 0.5 };
    GLfloat specular_light[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat ambient_light[] = { 0.9, 0.9, 0.9, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position_diff);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position_spec);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
    glEnable(GL_LIGHTING);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    // 3D Dependenci
    glShadeModel(GL_FLAT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);

}

void myIdle()
{
    display();
}

int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600,800);
	glutInitWindowPosition(10,10);
	glutCreateWindow("170411100061 - Tugas UAS - Sheep Fighter");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(kunci);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
    glutSpecialFunc(specKey);
	glutIdleFunc(myIdle);
	myinit();
	glutMainLoop();
	return 0;
}
