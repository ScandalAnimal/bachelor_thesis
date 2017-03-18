CFLAGS=-std=c11 -Wall -pedantic -g
EXEC=project
CC=gcc
RM=rm -f

all: hashmap.o node.o utils.o variable.o main.o
	$(CC) $(CFLAGS) -o $(EXEC) hashmap.o node.o utils.o variable.o main.o

clean:
	$(RM) *.o $(EXEC)

run:
	./$(EXEC)