This exercise will familiarize you with some file operations.
You are not allowed to store the contents of the file in an array.
All operations must be performed on the file.

# Learning Goals 

1. To learn how to open and close a file
2. To learn how to use fgetc to obtain a character from a file
    and to use fputc to put a character to a file
3. To learn to go to a particular location of a file using
    fseek
4. To learn to create your own Makefile

## Submitting Your Assignment 

You must submit two files:

1. answer02.c
2. Makefile


# Overview 

You are given a mazefile. In this exercise, you will write functions to:

1.  Determine the dimensions of the maze. (2 points)
2.  Count the number of locations that are PATH. (2 points)
3.  Given the row and column coordinates, determine whether that
     location is WALL or PATH. (2 points)
4.  Re-represent the maze in a single line in a new file (2 points).  

More details of the functions are provided below.

## Input file format 

In this exercise, we are concerned with only rectangular mazes.
A maze is made up of r rows and c columns.  For example, the
input file which contains the following lines describes
a maze with `r = 5 and c = 6`:
```
###s##
#....#
#...##
###.##
###e##
```
Note that in the input file, it would contain exactly 5 lines.
Moreover, there is a newline '\n' character at the end of each line.
Characters 's' and 'e' represent opening locations to the maze.

Therefore, there are really 7 characters in each line (6 '#' or '.'+ 1 newline '\n').

We number the rows from top to bottom as row 0 through row 4,
and the columns from left to right as column 0 through column 5.
This maze is in the file `maze5x6`.

You may assume that every sample file pointer contains a valid maze,
and that it has been successfully opened for read operations. 
However, you may not assume that the file location indicator
is at the beginning of a file.  Also, you should not close the given
file pointer in any of these five functions.  However, if you open
another file in your function, you are responsible for closing that
file.  We will use valgrind to make sure that you close all files
that you have opened.  Failure to close a file you have opened will
result in a 40% penalty.

## Functions to be written (8 points) 

The first function should determine the number of rows and the number
of columns of a given maze and store them in the parameters *nrow and *ncol.
The maze in our example has  5 rows and 6 columns, so *nrow and *ncol should
store 5 and 6, respectively.

The second function counts the number of locations that are PATH (or
'.', character space) and returns the value as an integer.  You should
include the openings in your count. For this example, there are 10 locations
that are PATH.

The third function has to determine whether the location specified
by given the row-column coordinates is a PATH or WALL.
For example, at location (1, 1), we have PATH.  At location (2, 0),
we have WALL.  The given coordinates will always be valid.  You 
simply have to return the character ('#' or '.') at that location.

The fourth function has to re-represent the maze in a single line
in a new file.  For this example, the file should look like this:

`###s###....##...#####.#####e##`

There should be exactly 5*6 = 30 characters in this output file.  In other
words, there is no newline character at the end of the file. 
This one-line representation is in the file `maze5x6_one_line`.

These functions should be written in `answer02.c`.  A brief description
of these functions can be found in `answer02.h`.
If you want to include any extra header files, please do so in answer02.c file.
If you want to define extra functions, do so at the top of answer02.c file.   

## Makefile (2 points) 

You will have to write your own  main function so that you can test these
four functions.  However, you SHOULD write the main function in
a separate file called pa02.c. We have provided a sample pa02.c file.
You are not required to submit pa02.c. If you include the main function 
in answer02.c, we will not be able to compile your answer02.c,
and you will get zero for this exercise.  

The main function that the instructor will write also 
resides in pa02.c.  The following gcc command will be used for
compilation:

`gcc -std=c99 -Wall -Werror -Wshadow -Wvla -Wunreachable-code -g pa02.c answer02.c -o pa02`

You should write a Makefile so that you can compile your files
using the make command and generate an executable.  

We will use your submitted Makefile and our own Makefile to
compile your code.  If you code does not compile (by your Makefile
or by our Makefile), you will get zero for this exercise.

# Running valgrind 

compile the .c files into pa02 and run the following command:

`valgrind --log-file=log1 --tool=memcheck --leak-check=full ./pa02 <argument1> <argument2>` 

Valgrind is an extremely useful tool for finding problems in C
programs. It is free-software, and (for C) as good as any software
commercially available. Comparable commercial software is usually
worth a few thousand dollars per user!

It is a core goal of this course that you learn how to use Valgrind in
order to ensure that your exercises/assignments do not have memory or
programming errors.  Valgrind is an invaluable tool in an engineers toolbox 
to do what most people in society don't know how to do: ensure that something 
is correct.

Valgrind has many functions; however, in this course, we will concern
ourselves with the "memcheck" function. The memcheck function runs
your code in an emulated environment, and checks whether you access
any bits of memory that you shouldn't. Memcheck also tests to see if
you have allocated (asked for) memory that you never freed (gave
back). Together, these two types of memory problems are some of the
most pernicious programming problems in the world, and cost literally
billions of dollars each year. Valgrind will help you find these
problems.

The preceding command *runs* your program, but to check for errors, you must 
read the log file that you just generated: "log1". This file
contains a lot of information. If your solution has no memory errors,
then you will see at the end of the file something like:

   `ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)`

We will reduce your assignment grade by 40% for any valgrind errors.

## Warnings 

We will be calling these five functions in unpredictable fashion.
You cannot assume that the given file pointer will point at 
a particular location in the file.  If you do not set the file position
properly at the beginning of the function call, it is unlikely that you 
will pass any of our tests.  

Do not close the given file pointer in any of these functions.
However, you have to close files that you have opened in your functions.

Do not print error messages to stdout.  If you want to print error messages,
print them to stderr.
