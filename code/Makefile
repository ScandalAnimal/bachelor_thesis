CFLAGS=-std=c11 -Wall -pedantic -g
EXEC=project
CC=gcc
RM=rm -f

SRC=anf.o hashmap.o node.o utils.o variable.o main.o

all: $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

clean:
	$(RM) *.o $(EXEC)

run:
	./$(EXEC)