#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <ctype.h>

void clear();
void display();
void triangulo(float *pos);
void reta(float *pos);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);

float mousePos[6];
int screenSize=400, count=0;
char op;

int main(int argc, char *argv[]){

    op = 'r';
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(screenSize,screenSize);
	glutInitWindowPosition(400,400);
	glutCreateWindow("Atividade2-5");
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
    for (int i = 0; i < 6; i++) mousePos[i] = 0;
    count = 0;

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);
	
    switch (op)
    {
    case 't':
        triangulo(mousePos);
        break;
    
    case 'r':
        reta(mousePos);
        break;
    }
}

void triangulo(float *pos){
        glBegin(GL_TRIANGLES);
		    glVertex2f(pos[0],pos[1]);
            glVertex2f(pos[2],pos[3]);
            glVertex2f(pos[4],pos[5]);
	    glEnd();

	glFlush();
}

void reta(float *pos){
        glBegin(GL_LINES);
		    glVertex2f(pos[0],pos[1]);
            glVertex2f(pos[2],pos[3]);
	    glEnd();

	glFlush();
}

void mouse(int button, int state, int x, int y){

	switch (button)
	{
	case GLUT_LEFT_BUTTON:
        if(count == 0){
            if(state==GLUT_DOWN){
                mousePos[0] = (float)x/(screenSize/2) -1;
                mousePos[1] = -((float)y/(screenSize/2) -1);
                count++;
            }
        }else{
            if(count == 1){
                if(state==GLUT_DOWN){
                    mousePos[2] = (float)x/(screenSize/2) -1;
                    mousePos[3] = -((float)y/(screenSize/2) -1);
                    if(op=='r') {
                        count=0;
                        glutPostRedisplay();
                    }else count++;
                }
            }else{
                if(state==GLUT_DOWN){
                    mousePos[4] = (float)x/(screenSize/2) -1;
                    mousePos[5] = -((float)y/(screenSize/2) -1);
                    count=0;
                    glutPostRedisplay();
                }
            }
        }
		break;
	}
}

void keyboard(unsigned char key, int x, int y){
    key=tolower(key);
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
        case 't':
            clear();
            op='t';
            break;
        case 'r':
            clear();
            op='r';
            break;
        default:
            break;
    }
    glutPostRedisplay();
}
