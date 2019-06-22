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

Sheep mysheep = Sheep(1);

float sudut=0;
float rotX=0, rotY=0, rotZ=0;
float tempRotX=0, tempRotY=0, tempRotZ=0;

float angle = 0.0f;
float lx=0.0f,lz=-1.0f;
float x=0.0f, z=5.0f;
float deltaAngle = 0.0f;
int xOrigin = -1;

int model = 0;

float pos[] = {2,10.5,1.5};
float viewDir[] = {0,-1,0};
float alpha = 5;

float alphaTrans = 1;
int viewMode = 1;

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

void setView(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(viewMode == 2) {
        gluPerspective(90.0,1,1,200);
        gluLookAt(pos[0],pos[1],pos[2]+0.5,pos[0]+viewDir[0],pos[1]+viewDir[1],pos[2]+viewDir[2],0,0,1);
    }
    else{
        glOrtho (-105, 105, -105, 105, -1000.0, 1000.0);
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

void createGrass()
{
    glPushMatrix();
        glTranslated(0, 0, 0);
        cube(100, 10, 200);
    glPopMatrix();
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

    createGrass();

    glutSwapBuffers();
}

void kunci(unsigned char key, int x, int y)
{
    tempRotX=rotX;
    tempRotY=rotY;
    tempRotZ=rotZ;

    if (key == 'w' || key == 'W')
    {
        rotY += 5;
    }
    if (key == 's' || key == 'S')
    {
        rotY -= 5;
    }
    if (key == 'a' || key == 'A')
    {
        rotX += 5;
    }
    if (key == 'd' || key == 'D')
    {
        rotX -= 5;
    }
    if (key == 'z' || key == 'Z')
    {
        rotZ += 5;
    }
    if (key == 'x' || key == 'X')
    {
        rotZ -= 5;
    }
    if (key == 'v' || key == 'V')
    {
        viewMode < 2 ? viewMode += 1 : viewMode = 0;
    }

    if (key > 48 && key < 58)
    {
        model = key - 48;
    }

    display();
}

void specKey(int key, int x, int y)
{
    if (viewMode == 2) {
            if(key == GLUT_KEY_RIGHT ) {
                    alpha-=0.1;
                    viewDir[0] = cos(alpha);
                    viewDir[1] = sin(alpha);
            }else if(key == GLUT_KEY_LEFT) {
                    alpha+=0.1;
                    viewDir[0] = cos(alpha);
                    viewDir[1] = sin(alpha);
            }else if(key == GLUT_KEY_UP) {
                    pos[0]+=1*viewDir[0];
                    pos[1]+=1*viewDir[1];
                    pos[2]+=1*viewDir[2];
            }else if(key == GLUT_KEY_DOWN) {
                    pos[0]-=1*viewDir[0];
                    pos[1]-=1*viewDir[1];
                    pos[2]-=1*viewDir[2];
            }
            display();
            // cout << pos[0] << " " << pos[1] << " " << pos[2] << endl;
    }
}

void mouseButton(int button, int state, int x, int y)
{

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}

void mouseMove(int x, int y)
{

	// this will only be true when the left button is down
	if (xOrigin >= 0) {

		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.01f;

		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-105, 105, -105*(GLfloat)h/(GLfloat)w, 105*(GLfloat)h/(GLfloat)w, -100.0, 100.0);
    else
        glOrtho (-105*(GLfloat)w/(GLfloat)h, 105*(GLfloat)w/(GLfloat)h, -105, 105, -100.0, 100.0);
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
    sudut += 1;
    display();
 }

int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
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
