CC=gcc
CFLAGS=-I.
DEPS = BST.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: Main

Main: Main.o BST.o
	$(CC) -o Main Main.o BST.o

clean:
	rm -f *.o Main