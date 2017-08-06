EXE = pa02
FLAGS = -g -std=c99 -Wall -Werror -Wvla -Wunreachable-code
OBJ = pa02.o answer02.o

main: $(OBJ)
	gcc $(FLAGS) -o $(EXE) $(OBJ)

pa02.o: pa02.c answer02.h
	gcc -c pa02.c

answer02.o: answer02.c answer02.h
	gcc -c answer02.c

clean:
	rm $(OBJ)
