#include <GL/glut.h>
#include <stdio.h>

void render(void);

int main(int argc, char **argv){
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
		glutInitWindowSize(800,600);
		glutInitWindowPosition(100,100);
		glutCreateWindow("Main");
		glutDisplayFunc(render);
		glutMainLoop();

		return 0;
}

void render(void){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		float size = 0.1;

		for(int i = 0; i<10; i++){
				for(int j = 0; j<10; j++){
						glBegin(GL_POLYGON);

						glColor3f(1,0,0);
						glVertex2f(-1+size*j,1-size*i);

						glColor3f(0,1,0);
						glVertex2f(-1+size+size*j,1-size*i);

						glColor3f(0,0,1);
						glVertex2f(-1+size+size*j,1-size-size*i);

						glColor3f(1,0,0);
						glVertex2f(-1+size*j,1-size-size*i);

						glEnd();
						glFlush();
				}
		}

		glutSwapBuffers();
}
