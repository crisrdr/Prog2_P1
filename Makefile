####################### VARIABLES #######################

EXE_1 = p1_e1
OBJ_1 = point.o

EXE_2 = p1_e2
OBJ_2 = $(OBJ_1) map.o

GCC = gcc -c -Wall -pedantic

##################### COMANDOS MAKE #####################

all: $(EXE_1) $(EXE_2)

$(EXE_1): $(OBJ_1) $(EXE_1).o
	gcc -o $(EXE_1) $(OBJ__1) $(EXE_1).o

$(EXE_2): $(OBJ_2) $(EXE_2).o
	gcc -o $(EXE_2) $(OBJ_2) $(EXE_2).o

map.o: map.h map.c
	$(GCC) map.c

point.o: point.h point.c
	$(GCC) point.c

$(EXE_1).o: $(EXE_1).c
	$(GCC) $(EXE_1).c

clean:
	rm *.o $(EXE_1) $(EXE_2)

run1:
	./$(EXE_1)

run2:
	./$(EXE_2)

val1:
	valgrind --leak-check=full ./$(EXE_1)

val2:
	valgrind --leak-check=full ./$(EXE_2)