#include <GL/glut.h>
#include <stdio.h>
#include "array.c"
#include "array2.c"
#include <math.h>

// Callback functions
void render(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);

void gameTick(void);
void changeStatus(int index);
int neighbourValid(int position, int active);
int getNeighbourStatus(int position, int active);
int getIndex(float x, float y);

// Edit or Play indicator
int mode = 0;

int main(int argc, char **argv){
	// Initilization
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Main");
	// Callback functions
	glutDisplayFunc(render);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}

// Render everything
void render(void){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		float size = 0.02;
		int cols = 100;
		int rows = 100;

		// Draw the field
		for(int i = 0; i<cols; i++){
				for(int j = 0; j<rows; j++){
						glBegin(GL_POLYGON);
						if(game[i*100+j] == 0){
							glColor3f(!mode,!mode,!mode);
						}else{
							glColor3f(mode, mode, mode);
						}
						glVertex2f(-1+size*j,1-size*i);

						glVertex2f(-1+size+size*j,1-size*i);

						glVertex2f(-1+size+size*j,1-size-size*i);

						glVertex2f(-1+size*j,1-size-size*i);

						glEnd();
						glFlush();
				}
		}

		// Execute a gametick if it's in play-mode
		if(mode){
			gameTick();
		}

		glutPostRedisplay();
		glutSwapBuffers();
}

// Mouse callback
void mouse(int button, int state, int x, int y){
		// If in edit mode and the left mouse button is pressed, 
		// change the status of the cell you clicked on
		if((!mode) && (button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)){
				changeStatus(getIndex(x*1.0, y*1.0));
		}
}

// Keyboard callback
void keyboard(unsigned char key, int x, int y){
	// Invert mode if spacebar is pressed
	if(key == 32){
		mode = !mode;
	}
}

// The logic of the game. Checks and changes cells.
void gameTick(void){
	// Execute for every cell
	for(int i = 0; i<100; i++){
		for(int j = 0; j<100; j++){

			int activeCell = i*100+j;
			int neighbours = 0;

			// Get the number of neighbours of the current cell
			for(int i = 1; i<=8; i++){
				int ret = neighbourValid(i, activeCell);
				if(ret==1){
					neighbours += 1;
				}
			}
			// If alive
			if(game[activeCell] == 1){
				// Rule 1 - Underpopulation
				if(neighbours < 2){
					game2[activeCell] = 0;
				// Rule 2
				}else if((neighbours == 2) || (neighbours == 3)){
					game2[activeCell] = 1;
	
				// Rule 3 - Overpopulation
				}else if(neighbours > 3){
					game2[activeCell] = 0;
				}
			//If dead
			}else{
			// Rule 4 - Reproduction
				if(neighbours == 3){
					game2[activeCell] = 1;
				}else{
					game[activeCell] = 0;
				}	
			}
		}
	}
	// Copy the buffer into the main array
	for(int i = 0; i<sizeof(game)/sizeof(game[0]); i++){
		game[i] = game2[i];
	}
}

// TODO Rewrite function
//
// Returns if <position> is a valid neighbour of cell <active> 
// Either 1 or 0 or 404 (if the neighbour is not available due to corner/borders)
//
// Positions:
//
// 1 2 3
// 4 A 5
// 6 7 8
//
// A = Active(array index)
//
//
//
//
int neighbourValid(int position, int active){
	int y = active/100;
	int x = ((double)(active%100)/100)*100;

	// If border left
	if(x == 0){
		// If corner top left
		if(y == 0){
			if((position == 5) || (position == 7) || (position == 8)){
				return getNeighbourStatus(position, active);
			}else{
				return 404;
			}
		// If corner bottom left
		}else if(y == 99){
			if((position == 2) || (position == 3) || (position == 5)){
				return getNeighbourStatus(position, active);
			}else{
				return 404;
			}
		// Border left no special case
		}else{
			if((position == 2) || (position == 3) || (position == 5) || (position == 7) || (position == 8)){
				return getNeighbourStatus(position, active);
			}else{
				return 404;
			}
		}
	// If border right
	}else if(x == 99){
			// If corner top right
			if(y == 0){
				if((position == 4) || (position == 6) || (position == 7)){
					return getNeighbourStatus(position, active);
				}else{
					return 404;
				}
			// If corner bottom right
			}else if(y == 99){
				if((position == 1) || (position == 2) || (position == 4)){
					return getNeighbourStatus(position, active);
				}else{
					return 404;
				}
			// Border right no special case
			}else{
				if((position == 1) || (position == 2) || (position == 4) || (position == 6) || (position == 7)){
					return getNeighbourStatus(position, active);
				}else{
					return 404;
				}
			}
	// Border top
	}else if(y == 0){
			// If corner top left
			if(x == 0){
				if((position == 5) || (position == 7) || (position == 8)){
					return getNeighbourStatus(position, active);
				}else{
					return 404;
				}
			// If corner top right
			}else if(x == 99){
				if((position == 4) || (position == 6) || (position == 7)){
					return getNeighbourStatus(position, active);
				}else{
					return 404;
				}
			// Border top no special case
			}else{
				if((position == 4) || (position == 5) || (position == 6) || (position == 7) || (position == 8)){
					return getNeighbourStatus(position, active);
				}else{
					return 404;
				}
			}
	// Border bottom
	}else if(y == 99){
			// If corner bottom left
			if(x == 0){
				if((position == 2) || (position == 3) || (position == 5)){
					return getNeighbourStatus(position, active);
				}else{
					return 404;
				}
			// If corner bottom right
			}else if(x == 99){
				if((position == 1) || (position == 2) || (position == 4)){
					return getNeighbourStatus(position, active);
				}else{
					return 404;
				}
			// Border bottom no special case
			}else{
				if((position == 1) || (position == 2) || (position == 3) || (position == 4) || (position == 5)){
					return getNeighbourStatus(position, active);
				}else{
					return 404;
				}
			}
	}else{
		return getNeighbourStatus(position, active);
	}
}

// Returns status of cell <active> in positition <position> 
// Either 1 or 0 
//
// Positions:
//
// 1 2 3
// 4 A 5
// 6 7 8
//
// A = Active(array index)
int getNeighbourStatus(int position, int active){
	if(position == 1){
		return game[active-100-1];
	}else if(position == 2){
		return game[active-100];
	}else if(position == 3){
		return game[active-100+1];
	}else if(position == 4){
		return game[active-1];
	}else if(position == 5){
		return game[active+1];
	}else if(position == 6){
		return game[active+100-1];
	}else if(position == 7){
		return game[active+100];
	}else if(position == 8){
		return game[active+100+1];
	}
}


// getIndex by coordinates
int getIndex(float x, float y){
	return floor(y/6.0)*100+(floor(x/6.0));
}

// Inverts the value of cell <index>
void changeStatus(int index){
	game[index] = !game[index];
}
