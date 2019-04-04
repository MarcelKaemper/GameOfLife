#include <GL/glut.h>
#include <stdio.h>
#include "array.c"
#include <math.h>

void render(void);
void mouse(int button, int state, int x, int y);
int getIndex(float x, float y);
void changeStatus(int index);

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Generator");
	glutDisplayFunc(render);
	glutMouseFunc(mouse);
	glutMainLoop();

	return 0;
}

// Render everything
void render(void){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		float size = 0.02;
		int cols = 100;
		int rows = 100;

		for(int i = 0; i<cols; i++){
				for(int j = 0; j<rows; j++){
						glBegin(GL_POLYGON);
						if(game[i*100+j] == 0){
							glColor3f(0,0,0);
						}else{
							glColor3f(1,1,1);
						}
						glVertex2f(-1+size*j,1-size*i);

						glVertex2f(-1+size+size*j,1-size*i);

						glVertex2f(-1+size+size*j,1-size-size*i);

						glVertex2f(-1+size*j,1-size-size*i);

						glEnd();
						glFlush();
				}
		}

		glutPostRedisplay();
		glutSwapBuffers();
}

void mouse(int button, int state, int x, int y){
		if((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)){
				printf("%f, %f\n", floor(x/10.0), floor(y/10.0));
				int index = getIndex(x*1.0, y*1.0);
				changeStatus(index);
		}

}

int getIndex(float x, float y){
	printf("%f, %f\n", floor(x/10.0), floor(y/10.0));
	return floor(y/10.0)*100+(floor(x/10.0));
}

void changeStatus(int index){
	game[index] = !game[index];
}
