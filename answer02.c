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

	fseek(fptr, 0, SEEK_SET); // reach the end of file
	
	int f;

	while(f != EOF){ 
 
	f = fgetc(fptr);

	if(f == '\n'){  // count the rows
	(*nrow)++;}
	}
    
	
	int length = (int) ftell(fptr);	 // count the number of characters in the file
	*ncol =  (length / (*nrow)) - 1; // total number of characters divided by rows
}

/* Count the number of locations that are PATH */
/* A location is PATH if it is a space, ' ', or '.' */
/* you may assume that the maze is of the correct format */

int Count_path_locations(FILE *fptr)
{
	int count = 0;
	fseek(fptr, 0, SEEK_SET);

	int f = fgetc(fptr);
	while(f != EOF){
	if(f == ' ' || f == '.' || f == 's' || f == 'e'){ 
	count++;}
	f = fgetc(fptr);
	}

   return count;
}

/* Return the type of location: WALL or PATH */
/* The location is specified by its row-column coordinates. */
/* The coordinates are specified by row and col */
/* you may assume that these coordinates are always valid */
/* you may assume that the maze is of the correct format */

void Get_location_type(FILE *fptr) {
	
	fseek(fptr, 0, SEEK_SET);		
	int f = fgetc(fptr);	
	int nrow = 0, ncol = 0;

	while(f != EOF)
	{	
		if(f == '\n'){
		nrow++;
		ncol = 0;
		}		
		else{ 
			if(f == '.' || f == 's' || f == 'e')
			{
				printf("%d %d PATH\n", nrow, ncol);
			}
			else
			{
				printf("%d %d WALL\n", nrow, ncol);
			}
			ncol++;
		}
		f = fgetc(fptr);
	}
return;
}
 
/* Given a filename, re-represent the maze in the file pointer fptr */
/* in a single line */
/* The return value should be the number of characters written into the */
/* the new file */
/* if the writing to a file fails, you should return -1 */ 
/* you may assume that the maze is of the correct format */

int Represent_maze_in_one_line(char *filename, FILE * fptr)
{
	FILE * output = fopen(filename, "w");
	if (output == NULL) {
		fprintf(stderr, "Error opening file");
		return 0;
  	}	

	fseek(fptr, 0, SEEK_SET) ;
	int f = fgetc(fptr);
	int count = 0;
	while (f != EOF) 
	{
		if (f != '\n'){
		fprintf(output, "%c", (char) f);}
		f = fgetc(fptr);
		count++;
	}
	fclose(output);
	return count;
}
