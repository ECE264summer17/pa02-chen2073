#include <stdio.h>
#include <stdlib.h>
#include "answer02.h"

int main(int argc, char* argv[]) 
{
  if (argc != 3) 
  {
      return EXIT_FAILURE;
  }
  
  FILE * fptr = fopen(argv[1], "r");

  if (fptr == NULL) 
  {
      return EXIT_FAILURE;
  }

  /* first move to end of file */ 

  fseek(fptr, 0, SEEK_END);
  
  /* testing for Find_maze_dimensions */

  int nrow = 0;
  int ncol = 0;
  Find_maze_dimensions(fptr, &nrow, &ncol);
  printf("Find_maze_dimensions : %dx%d\n", nrow, ncol);

  /* testing for Count_path_locations */

  int path_counts = Count_path_locations(fptr);
  printf("Count_path_locations : ");
  printf("%d\n", path_counts);

  /* testing for Get_location_type */

  printf("Get_location_type : ");
  Get_location_type(fptr);
 /* loop counters for row and column */

  /* testing for Represent_maze_in_one_line */
  printf("Represent_maze_in_one_line : ");
  int char_count = Represent_maze_in_one_line(argv[2], fptr);
  printf("%d\n", char_count);

  fclose(fptr);
  return EXIT_SUCCESS;
}
