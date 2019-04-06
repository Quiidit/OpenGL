#include <windows.h>
#include <gl\glut.h>                  
#include <gl\GL.h>                     
#include <gl\GLU.h>   
#include<stdio.h>
GLfloat Delta = 0.0; //타이머 콜백
GLfloat idle = 0.001;
void MyDisplay() {

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0 , -1.0 + Delta, 0.0);//좌하단
	glVertex3f(0.0, -1.0 + Delta, 0.0); //우하단
	glVertex3f(0.0, 0.0 + Delta, 0.0); //좌상단
	glVertex3f(-1.0, 0.0 + Delta, 0.0); //우상단


	glEnd();
	glutSwapBuffers();

}

void MyIdle() {
	Delta = Delta + idle;
	MyDisplay();
	glutPostRedisplay();
}

void MyTimer(int Value) {
	glutIdleFunc(MyIdle);
	if ((Delta > 2.0) || (Delta < -1.0))
		idle *= -1;
	glutTimerFunc(1, MyTimer, 1);
}


int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(1, MyTimer, 1);
	glutMainLoop();
	return 0;
}