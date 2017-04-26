CFLAGS=-std=c11 -Wall -pedantic -g
EXEC=project
TEST=test
CC=gcc
RM=rm -f
RMDIR=rm -rf
MKDIR=mkdir

SRC=anf.o graph.o hashmap.o node.o utils.o variable.o
MAIN=main.o
TESTS=tests.o
TEST_OUTPUT=./testOutput

LIB_FILES=$(SRC) $(MAIN)
TEST_FILES=$(SRC) $(TESTS)

all: $(LIB_FILES)
	$(CC) $(CFLAGS) -o $(EXEC) $(LIB_FILES)

clean:
	$(RM) *.o $(EXEC) $(TEST) $(TEST_OUTPUT)/*
	$(RMDIR) $(TEST_OUTPUT)

run:
	./$(EXEC)

test: $(TEST_FILES)
	$(RM) $(TEST_OUTPUT)/*
	$(CC) $(CFLAGS) -o $(TEST) $(TEST_FILES)
	./$(TEST)