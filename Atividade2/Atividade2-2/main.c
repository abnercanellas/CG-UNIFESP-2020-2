#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void clear();
void display();
void mouse();
void keyboard(unsigned char key, int x, int y);

float mouseX=0, mouseY=0;
int screenSize = 400;

int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(screenSize,screenSize);
	glutInitWindowPosition(400,400);
	glutCreateWindow("Atividade2-2");
	clear();
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
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

void keyboard(unsigned char key, int x, int y){

	switch (key){
	case '0':
          glColor3f(1.0,1.0,1.0);
          break;
       case '1':
          glColor3f(0.0,0.0,0.0);
          break;
       case '2':
          glColor3f(1.0,0.0,0.0);
          break;
       case '3':
          glColor3f(0.0,1.0,0.0);
          break;
       case '4':
          glColor3f(0.0,0.0,1.0);
          break;
       case '5':
          glColor3f(0.0,1.0,1.0);
          break;
       case '6':
          glColor3f(1.0,0.0,1.0);
          break;
       case '7':
          glColor3f(1.0,1.0,0.0);
          break;
       case '8':
          glColor3f(0.5,0.5,0.5);
          break;
       case '9':
          glColor3f(0.5,1.0,0.5);
          break;
    }
    glutPostRedisplay();
}
