#include <stdio.h>
#include <stdlib.h>
#include "answer02.h"

/* Determine the dimensions of the maze contain in file. */
/* The maze will always be of the correct format */
/* the number of rows is to be stored at location pointed to by nrow */ 
/* the number of ncol is to be stored at location pointed to by ncol */

void Find_maze_dimensions(FILE *fptr, int *nrow, int *ncol)
{
   *nrow = *ncol = 0;
}

/* Count the number of locations that are PATH */
/* A location is PATH if it is a space, ' ', or '.' */
/* you may assume that the maze is of the correct format */

int Count_path_locations(FILE *fptr)
{
   return 0;
}

/* Return the type of location: WALL or PATH */
/* The location is specified by its row-column coordinates. */
/* The coordinates are specified by row and col */
/* you may assume that these coordinates are always valid */
/* you may assume that the maze is of the correct format */

char Get_location_type(FILE *fptr, int row, int col) {
   return 0;
}
 
/* Given a filename, re-represent the maze in the file pointer fptr */
/* in a single line */
/* The return value should be the number of characters written into the */
/* the new file */
/* if the writing to a file fails, you should return -1 */ 
/* you may assume that the maze is of the correct format */

int Represent_maze_in_one_line(char *filename, FILE *fptr)
{
   return 0;
}
