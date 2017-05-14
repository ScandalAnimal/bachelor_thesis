CFLAGS=-std=c11 -Wall -Werror -pedantic -g
EXEC=test
CC=gcc
RM=rm -f
RMDIR=rm -rf

TESTS=tests.c
SO=libanf.so
TEST_OUTPUT=./testOutput

all: test

clean:
	$(RM) *.o $(EXEC)
	$(RMDIR) $(TEST_OUTPUT)

run:
	./$(EXEC)

test: $(TESTS)
	$(RM) $(TEST_OUTPUT)/*
	$(CC) $(CFLAGS) -o $(EXEC) $(TESTS) -lanf