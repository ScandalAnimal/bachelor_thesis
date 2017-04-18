CFLAGS=-std=c11 -Wall -pedantic -g
EXEC=project
TEST=test
CC=gcc
RM=rm -f

SRC=anf.o hashmap.o node.o utils.o variable.o
MAIN=main.o
TESTS=tests.o

LIB_FILES=$(SRC) $(MAIN)
TEST_FILES=$(SRC) $(TESTS)

all: $(LIB_FILES)
	$(CC) $(CFLAGS) -o $(EXEC) $(LIB_FILES)

clean:
	$(RM) *.o $(EXEC) $(TEST)

run:
	./$(EXEC)

test: $(TEST_FILES)
	$(CC) $(CFLAGS) -o $(TEST) $(TEST_FILES)
	./$(TEST)