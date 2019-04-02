#include <GL/glut.h>
#include <stdio.h>
#include "array.c"
#include <math.h>

void render(void);
void gameTick(void);
int neighbourValid(int position, int active);

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

// Render everything
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

// The logic of the game. Checks and changes cells.
void gameTick(void){
		for(int i = 0; i<100; i++){
				for(int j = 0; j<100; j++){
						int activeCell = i*100+j;
						printf("%d\n", activeCell);
						printf("%d",neighbourValid(1, activeCell));
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




// Returns if <position> is a valid neighbour of cell <active> 
// Either 1 or 0
//
// Positions:
//
// 1 2 3
// 4 A 5
// 6 7 8
//
// A = Active(array index)

int neighbourValid(int position, int active){
	int y = active/100;
	int x = ((double)(active%100)/100)*100;

	// If border left
	if(x == 0){
		// If corner top left
		if(y == 0){
			if((position == 5) || (position == 7) || (position == 8)){
				return 1;
			}else{
				return 0;
			}
		// If corner bottom left
		}else if(y == 99){
			if((position == 2) || (position == 3) || (position == 5)){
				return 1;
			}else{
				return 0;
			}
		// Border left no special case
		}else{
			if((position == 2) || (position == 3) || (position == 5) || (position == 7) || (position == 8)){
				return 1;
			}else{
				return 0;
			}
		}
	// If border right
	}else if(x == 99){
			// If corner top right
			if(y == 0){
				if((position == 4) || (position == 6) || (position == 7)){
					return 1;
				}else{
					return 0;
				}
			// If corner bottom right
			}else if(y == 99){
				if((position == 1) || (position == 2) || (position == 4)){
					return 1;
				}else{
					return 0;
				}
			// Border right no special case
			}else{
				if((position == 1) || (position == 2) || (position == 4) || (position == 6) || (position == 7)){
					return 1;
				}else{
					return 0;
				}
			}
	// Border top
	}else if(y == 0){
			// If corner top left
			if(x == 0){
				if((position == 5) || (position == 7) || (position == 8)){
					return 1;
				}else{
					return 0;
				}
			// If corner top right
			}else if(x == 99){
				if((position == 4) || (position == 6) || (position == 7)){
					return 1;
				}else{
					return 0;
				}
			// Border top no special case
			}else{
				if((position == 4) || (position == 5) || (position == 6) || (position == 7) || (position == 8)){
					return 1;
				}else{
					return 0;
				}
			}
	// Border bottom
	}else if(y == 99){
			// If corner bottom left
			if(x == 0){
				if((position == 2) || (position == 3) || (position == 5)){
					return 1;
				}else{
					return 0;
				}
			// If corner bottom right
			}else if(x == 99){
				if((position == 1) || (position == 2) || (position == 4)){
					return 1;
				}else{
					return 0;
				}
			// Border bottom no special case
			}else{
				if((position == 1) || (position == 2) || (position == 3) || (position == 4) || (position == 5)){
					return 1;
				}else{
					return 0;
				}
			}
	}else{
		return 1;
	}
	/* printf("x: %d\ny: %d\n\n", x, y); */
	/* char c; */
	/* scanf("%c",&c); */
}
