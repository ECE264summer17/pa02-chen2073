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

	fseek(fptr, 0, SEEK_SET);// reach the end of file
	
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
	char f = 0;

	do{
	f = fgetc(fptr);

	if(f == ' ' || f == '.' || f == 's' || f == 'e'){ 
	count++;
	}
	}while(f != EOF);

   return count;
}

/* Return the type of location: WALL or PATH */
/* The location is specified by its row-column coordinates. */
/* The coordinates are specified by row and col */
/* you may assume that these coordinates are always valid */
/* you may assume that the maze is of the correct format */

char Get_location_type(FILE *fptr, int row, int col) {
	
	int nrow=0;
	int ncol=0; 
	int f;
 
	fseek(fptr, 0, SEEK_SET) ;
	for(nrow=0; nrow <= row; nrow++){

		
	
		for(ncol=0; ncol <= col; ncol++){
					
		f = fgetc(fptr);	

		}
	}
			
			if(f == '.' || f == 's' || f == 'e'){
				return PATH;
			}

			else{
				return WALL;
			}
//return 0;
}
 
/* Given a filename, re-represent the maze in the file pointer fptr */
/* in a single line */
/* The return value should be the number of characters written into the */
/* the new file */
/* if the writing to a file fails, you should return -1 */ 
/* you may assume that the maze is of the correct format */

int Represent_maze_in_one_line(char *filename, FILE *fptr)
{

	FILE * fp = fopen(filename, "w");
	int f ;

	fseek(fptr, 0, SEEK_SET) ;

	if (fp == NULL) {
		fprintf(stderr, "Error opening file");
		return -1;
  	}	
	
	while ((f = fgetc(fptr)) != EOF) {
		if (f != '\n'){
			fputc(f, fp) ;
		}
	}

	fclose(fp);

	return 0;
}
