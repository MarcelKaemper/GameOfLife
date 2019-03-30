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

		int cols = 4;
		int rows = 4;
		int game[16] = {1,0,1,0,
						1,1,1,1,
						1,1,0,1,
						1,0,1,0};

		for(int i = 0; i<cols; i++){
				for(int j = 0; j<rows; j++){
						glBegin(GL_POLYGON);

						if(game[i*4+j] == 0){
							glColor3f(1,0,0);
						}else{
							glColor3f(0,0,1);
						}
						glVertex2f(-1+size*j,1-size*i);

						glVertex2f(-1+size+size*j,1-size*i);

						glVertex2f(-1+size+size*j,1-size-size*i);

						glVertex2f(-1+size*j,1-size-size*i);

						glEnd();
						glFlush();
				}
		}

		glutSwapBuffers();
}
