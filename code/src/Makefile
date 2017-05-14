CFLAGS=-std=c11 -Wall -Werror -pedantic -g
CC=gcc
RM=rm -f
OSRC=anf.o anfgraph.o anfhashmap.o anfnode.o anfutils.o anfvariable.o
CSRC=anf.c anfgraph.c anfhashmap.c anfnode.c anfutils.c anfvariable.c
SO=libanf.so
INCLUDE=/usr/local/include

all: install	

clean:
	$(RM) *.o
	$(RM) $(SO)

install:
	$(CC) -c $(CFLAGS) -fpic $(CSRC)
	$(CC) -shared -o $(SO) $(OSRC)
	cp $(SO) /usr/local/lib
	cp anf.h $(INCLUDE)
	cp anfgraph.h $(INCLUDE)
	cp anferror.h $(INCLUDE)
	cp anfhashmap.h $(INCLUDE)
	cp anfnode.h $(INCLUDE)
	cp anfutils.h $(INCLUDE)
	cp anfvariable.h $(INCLUDE)
	cp uthash.h $(INCLUDE)
	chmod 0755 /usr/local/lib/$(SO)
	ldconfig
	unset LD_LIBRARY_PATH
	$(RM) *.o
	$(RM) $(SO)