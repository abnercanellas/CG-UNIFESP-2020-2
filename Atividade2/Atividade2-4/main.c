#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void clear();
void display();
void mouse();
void keyboard(unsigned char key, int x, int y);

float mouseX1=0, mouseY1=0, mouseX2=0, mouseY2=0;
int screenSize=400, count=0;

int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(screenSize,screenSize);
	glutInitWindowPosition(400,400);
	glutCreateWindow("Atividade2-4");
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
	keyboard('0', 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

}

void display(){

    if (count!=0){
        glBegin(GL_LINE_STRIP);
		      glVertex2f(mouseX1, mouseY1);
            glVertex2f(mouseX2, mouseY2);
	    glEnd();
    }

	glFlush();

}

void mouse(int button, int state, int x, int y){

	switch (button)
	{
	case GLUT_LEFT_BUTTON:
        if(count == 0 || count == 1){
            if(state==GLUT_DOWN){
                mouseX1 = (float)x/(screenSize/2) -1;
                mouseY1 = -((float)y/(screenSize/2) -1);
                count==0 ? count=+2:count++;
            }
        }else if(state==GLUT_DOWN){
                mouseX2 = (float)x/(screenSize/2) -1;
                mouseY2 = -((float)y/(screenSize/2) -1);
                count = 1;
                glutPostRedisplay();
            }

		break;
	}
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
