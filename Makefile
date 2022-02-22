####################### VARIABLES #######################

EXE_1 = p1_e1
OBJ_1 = point.o $(EXE_1).o

EXE_2 = p1_e2
OBJ_2 = point.o map.o $(EXE_1).o $(EXE_2).o

GCC = gcc -c -Wall -pedantic

##################### COMANDOS MAKE #####################

## GENERAL ##

all: $(EXE_1) $(EXE_2)

clean:
	rm *.o $(EXE_1) $(EXE_2)

## APARTADO 1 ##

$(EXE_1): $(OBJ_1)
	gcc -o $(EXE_1) $(OBJ_1)
	
$(EXE_1).o: $(EXE_1).c
	$(GCC) $(EXE_1).c

point.o: point.h point.c
	$(GCC) point.c

run1:
	./$(EXE_1)

val1:
	valgrind --leak-check=full ./$(EXE_1)

## APARTADO 2 ##

$(EXE_2): $(OBJ_2)
	gcc -o $(EXE_2) $(OBJ_2)

$(EXE_2).o: $(EXE_2).c
	$(GCC) $(EXE_2).c

map.o: map.h map.c
	$(GCC) map.c

run2:
	./$(EXE_2)

val2:
	valgrind --leak-check=full ./$(EXE_2)