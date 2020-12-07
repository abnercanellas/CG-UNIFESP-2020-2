#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void clear();
void display();
void mouse();

float mouseX=0, mouseY=0;
int screenSize = 400;

int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(screenSize,screenSize);
	glutInitWindowPosition(400,400);
	glutCreateWindow("Atividade2-1");
	clear();
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	glutMainLoop();


	return 0;
}

void clear(){

	glClearColor(0.23,0.25,0.25,0);
	glPointSize(5);
	glColor3f(0,0,1);

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
		glVertex2f(mouseX, mouseY);
	glEnd();

	glFlush();

}

void mouse(int button, int state, int x, int y){

	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN){
			mouseX = (float)x/(screenSize/2) -1;
			mouseY = -((float)y/(screenSize/2) -1);
		}
		break;

	default:
		break;
	}
	glutPostRedisplay();
}
