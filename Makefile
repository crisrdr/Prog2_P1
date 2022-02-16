all: p1_e1

p1_e1: point.o p1_e1.o
	gcc -o p1_e1 point.o p1_e1.o

point.o: point.h point.c
	gcc -c point.c

p1_e1.o: p1_e1.c
	gcc -c p1_e1.c

clean:
	rm *.o p1_e1

run:
	./p1_e1

val:
	valgrind --leak-check=full ./p1_e1