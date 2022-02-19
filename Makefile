####################### VARIABLES #######################

EXE = p1_e1
OBJ = point.o map.o
GCC = gcc -c -Wall -pedantic

##################### COMANDOS MAKE #####################

all: $(EXE)

$(EXE): $(OBJ) $(EXE).o
	gcc -o $(EXE) $(OBJ) $(EXE).o

map.o: map.h map.c
	$(GCC) map.c

point.o: point.h point.c
	$(GCC) point.c

$(EXE).o: $(EXE).c
	$(GCC) $(EXE).c

clean:
	rm *.o $(EXE)

run:
	./$(EXE)

val:
	valgrind --leak-check=full ./$(EXE)