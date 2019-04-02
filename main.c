#include <GL/glut.h>
#include <stdio.h>
#include "array.c"
#include <math.h>

void render(void);
void gameTick(void);
int getNeighbours(int position, int active);

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

		float size = 0.015;
		int cols = 100;
		int rows = 100;


		for(int i = 0; i<cols; i++){
				for(int j = 0; j<rows; j++){
						glBegin(GL_POLYGON);

						if(game[i*100+j] == 0){
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
		gameTick();

		glutPostRedisplay();
		glutSwapBuffers();
}

void gameTick(void){
		for(int i = 0; i<100; i++){
				for(int j = 0; j<100; j++){
						int activeCell = i*100+j;
						printf("%d\n", activeCell);
						getNeighbours(7, activeCell);
						// If alive
						if(game[activeCell]){
								// Rule 1 - Underpopulation
								
								// Kill
								/* game[i*100+j] = 0; */

								// Rule 2 
								// Rule 3 - Overpopulation

						//If dead
						}else{
								// Rule 4 - Reproduction
								
								// Revive
								/* game[i*100+j] = 1; */

						}
				}
		}
}

// Position:
//
// 1 2 3
// 4 A 5
// 6 7 8
//
// A = Active(array index)
// Returns dead or alive

int getNeighbours(int position, int active){
	int y = active/100;
	int x = ((double)(active%100)/100)*100;

	printf("x: %d\ny: %d\n\n", x, y);
	char c;
	scanf("%c",&c);

	return 1;
}
