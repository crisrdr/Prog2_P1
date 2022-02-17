EXE = p1_e1

all: $(EXE)

$(EXE): point.o $(EXE).o
	gcc -o $(EXE) point.o $(EXE).o

point.o: point.h point.c
	gcc -c point.c

$(EXE).o: $(EXE).c
	gcc -c $(EXE).c

clean:
	rm *.o $(EXE)

run:
	./$(EXE)

val:
	valgrind --leak-check=full ./$(EXE)