    #define _USE_MATH_DEFINES 

#include <cstdlib>
#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 
#define pi = 3.14

//MUHAMMAD ANDHIKA ADHISATYA
//5221600011
//ALFIAN MAJIDDAN NUR
//5221600021

static float X = 0.0;
static float Y = 0.0;
static float Z = -9.0;

setColor(0,0,1);
for(i=0;i<prisma.NumberofFaces;i++)
{
for(j=0;j<prisma.fc[i].NumberofVertices;j++)
vecbuff[j]=vec[prisma.fc[i].pnt[j]];
NormalVector=(vecbuff[1]-vecbuff[0])^(vecbuff[2]-vecbuff[0]);
normalzi=NormalVector.v[2];
if(normalzi<0.)
{
for(j=0;j<prisma.fc[i].NumberofVertices;j++)
titik2D[j]=Vector2Point2D(vec[prisma.fc[i].pnt[j]]);
drawPolygon(titik2D,prisma.fc[i].NumberofVertices);
}
}

setColor(0,1,1);
for(i=0;i<prisma.NumberofFaces;i++)
{
for(j=0;j<prisma.fc[i].NumberofVertices;j++)
vecbuff[j]=vec[prisma.fc[i].pnt[j]];
NormalVector=(vecbuff[1]-vecbuff[0])^(vecbuff[2]-vecbuff[0]);
normalzi=NormalVector.v[2];
if(normalzi>0.)
{
for(j=0;j<prisma.fc[i].NumberofVertices;j++)
titik2D[j]=Vector2Point2D(vec[prisma.fc[i].pnt[j]]);
drawPolygon(titik2D,prisma.fc[i].NumberofVertices);
}
}

void drawScene(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glLoadIdentity();
	glTranslatef(X, Y, Z);

	glFlush();
	glutSwapBuffers();
}

void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'a':
		X+=0.5;
		glutPostRedisplay();
		break;
	case 'd':
		X -= 0.5;
		glutPostRedisplay();
		break;
	case 's':
		Y -= 0.5;
		glutPostRedisplay();
		break;
	case 'w':
		Y += 0.5;
		glutPostRedisplay();
		break;
	case 'q':
		Z -= 0.5;
		glutPostRedisplay();
		break;
	case 'e':
		Z += 0.5;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Grafik3D.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}