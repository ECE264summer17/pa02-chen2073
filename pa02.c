#include <stdio.h>
#include <stdlib.h>
#include "answer02.h"

int main(int argc, char* argv[]) 
{
  FILE *fptr = NULL;
  if (argc != 3) 
  {
      return EXIT_FAILURE;
  }
  
  if ((fptr = fopen(argv[1], "r")) == NULL) 
  {
      return EXIT_FAILURE;
  }

  /* first move to end of file */ 

  fseek(fptr, 0, SEEK_END);
  
  /* testing for Find_maze_dimensions */

  int nrow, ncol;
  Find_maze_dimensions(fptr, &nrow, &ncol);
  printf("Find_maze_dimensions : ");
  printf("%d %d\n", nrow, ncol);


  /* testing for Count_path_locations */

  int path_counts = Count_path_locations(fptr);
  printf("Count_path_locations : ");
  printf("%d\n", path_counts);

  /* testing for Get_location_type */

  int nnrow, nncol;
  printf("Get_location_type : ");
  Find_maze_dimensions(fptr, &nnrow, &nncol);
  int row, col; /* loop counters for row and column */
  for (col = 0; col < nncol; col++) {
     for (row = 0 ; row < nnrow; row++) {
	char loc_type = Get_location_type(fptr, row, col);
        if (loc_type == PATH) {
           printf("%d %d PATH\n", row, col);
	} else if (loc_type == WALL) {
           printf("%d %d WALL\n", row, col);
        } else {
           printf("%d %d incorrect\n", row, col);
        }
     }
  } 


  /* testing for Represent_maze_in_one_line */
  printf("Represent_maze_in_one_line : ");
  int char_count = Represent_maze_in_one_line(argv[2], fptr);
  printf("%d\n", char_count);

  fclose(fptr);
  return EXIT_SUCCESS;
}
