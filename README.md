# GameOfLife
Conway's Game of Life in C/OpenGL  

## Math 
### Index by gridpos
max = max amount of elements in a row  
x,y = coordinates  

<img src="https://latex.codecogs.com/gif.latex?\large&space;index&space;=&space;y&space;\cdot&space;max&space;&plus;&space;x" title="\large index = y \cdot max + x" />

### Gridpos by index:  
max = max amount of elements in a row  
x:  
  
<img src="https://latex.codecogs.com/gif.latex?\large&space;x&space;=&space;max&space;\left&space;(&space;\frac{index\%max}{max}&space;\right&space;)" title="\large x = max \left ( \frac{index\%max}{max} \right )" />
  
y:  
  
<img src="https://latex.codecogs.com/gif.latex?\large&space;y&space;=&space;\frac{index}{max}" title="\large y = \frac{index}{max}" />

