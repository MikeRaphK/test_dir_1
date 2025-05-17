CC=gcc
CFLAGS=-I.

all: fibonacci

fibonacci: fibonacci.o
	$(CC) -o fibonacci fibonacci.o

fibonacci.o: fibonacci.c
	$(CC) -c fibonacci.c

clean:
	rm -f *.o fibonacci
