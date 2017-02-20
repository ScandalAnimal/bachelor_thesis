CFLAGS=-std=c11 -Wall -pedantic -g
EXEC=project
CC=gcc
RM=rm -f

all: evaluator.o hashmap.o utils.o main.o
	$(CC) $(CFLAGS) -o $(EXEC) evaluator.o hashmap.o utils.o main.o

clean:
	$(RM) *.o $(EXEC)

run:
	./$(EXEC)