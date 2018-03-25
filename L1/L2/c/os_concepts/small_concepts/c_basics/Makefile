#specify the compiler
CC=gcc

#specify options for the compiler 
CFLAGS=-c -Wall -g

all: hello

hello: main.o hello.o utils.o my_lib.o 
	$(CC) main.o hello.o utils.o my_lib.o -o hello
main.o: main.c
	$(CC) $(CFLAGS) main.c main.h
hello.o: hello.c
	$(CC) $(CFLAGS) hello.c hello.h
utils.o: utils.c
	$(CC) $(CFLAGS) utils.c utils.h
my_lib.o: my_lib.c
	$(CC) $(CFLAGS) my_lib.c my_lib.h

clean: 
	rm -rf *.o hello
