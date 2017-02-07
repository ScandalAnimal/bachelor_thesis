CFLAGS=-std=c11 -Wall -pedantic -g
EXEC=project
CC=gcc
RM=rm -f

all: inputs.o hashmap.o main.o
	$(CC) $(CFLAGS) -o $(EXEC) inputs.o hashmap.o main.o

clean:
	$(RM) *.o $(EXEC)

run:
	./$(EXEC)