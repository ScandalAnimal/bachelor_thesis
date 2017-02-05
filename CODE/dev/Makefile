CFLAGS=-std=c11 -Wall -pedantic -g
BIN=project
CC=gcc
RM=rm -f

all: inputs.o hashmap.o main.o
	$(CC) $(CFLAGS) -o $(BIN) inputs.o hashmap.o main.o

clean:
	$(RM) *.o $(BIN)

run:
	./$(BIN)