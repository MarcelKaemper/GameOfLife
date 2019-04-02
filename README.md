# GameOfLife  
This was my first project in C and also the first one with OpenGL/glut.  
I safe the status of each cell in a 100x100 array as you can see in array.c. This is obviously not the best solution.  
I created a javascript program that creates the array and outputs it in the console.    

## Compilation
Using gcc:  
```
gcc -lGL -lglut -lm main.c
```

## Math  
The formulas I developed to find either the index of the element when x and y coordinates are given or the x and y coordinates when the index is given.  
max = max amount of elements in a row
x,y = coordinates  
  
### Index by gridpos
<img src="https://latex.codecogs.com/gif.latex?\large&space;index&space;=&space;y&space;\cdot&space;max&space;&plus;&space;x" title="\large index = y \cdot max + x" />

### Gridpos by index:  
<img src="https://latex.codecogs.com/gif.latex?\large&space;x&space;=&space;max&space;\left&space;(&space;\frac{index\%max}{max}&space;\right&space;)" title="\large x = max \left ( \frac{index\%max}{max} \right )" />  
  
<img src="https://latex.codecogs.com/gif.latex?\large&space;y&space;=&space;\frac{index}{max}" title="\large y = \frac{index}{max}" />

