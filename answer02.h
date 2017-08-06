#ifndef pa02_H
#define pa02_H 

#define WALL '#'
#define PATH '.'

#include <stdio.h>

/* Determine the dimensions of the maze contain in file. */
/* The maze will always be of the correct format */
/* the number of rows is to be stored at location pointed to by nrow */ 
/* the number of ncol is to be stored at location pointed to by ncol */

void Find_maze_dimensions(FILE *fptr, int *nrow, int *ncol);
			
/* Count the number of locations that are PATH  */
/* A location is a PATH if it is a dot charater, '.', or PATH */
/* You may assume that the maze is of the correct format */

int Count_path_locations(FILE *fptr);

/* Return the type of location: WALL or PATH, i.e. '#' or '.' */
/* In other words, return the character in the file for that location */ 
/* The location is specified by its row-column coordinates. */
/* The coordinates are specified by row and col */
/* These coordinates will always be valid for the given maze */
/* You do not have to worry about the coordinates being out of range */
/* You may assume that the maze is of the correct format */

void Get_location_type(FILE *fptr);
 
/* Given a filename, re-represent the maze in the file pointer fptr */
/* in a single line */
/* The return value should be the number of characters written into the */
/* the new file */
/* if the writing to a file fails, you should return -1 */ 
/* You may assume that the maze is of the correct format */

int Represent_maze_in_one_line(char *filename, FILE *fptr);

#endif
