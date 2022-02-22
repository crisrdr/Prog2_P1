####################### VARIABLES #######################

EXE1 = p1_e1
OBJ1 = point.o
EXE2 = p1_e2
OBJ2 = point.o map.o
GCC = gcc -c -Wall -pedantic

##################### COMANDOS MAKE #####################

all: $(EXE1) $(EXE2)

$(EXE1): $(OBJ1) $(EXE1).o
	gcc -o $(EXE1) $(OBJ1) $(EXE1).o

$(EXE2): $(OBJ2) $(EXE2).o
	gcc -o $(EXE2) $(OBJ2) $(EXE2).o

map.o: map.h map.c
	$(GCC) map.c

point.o: point.h point.c
	$(GCC) point.c

$(EXE1).o: $(EXE1).c
	$(GCC) $(EXE1).c

clean:
	rm *.o $(EXE1) $(EXE2)

run1:
	./$(EXE1)

run2:
	./$(EXE2)

val1:
	valgrind --leak-check=full ./$(EXE1)

val2:
	valgrind --leak-check=full ./$(EXE2)