all: sample

sample: sample.c
	gcc -c -Wall -Werror -fpic sample.c
	gcc -shared -o libsample.so sample.o
	cp libsample.so /usr/local/lib
	cp sample.h /usr/local/include
	chmod 0755 /usr/local/lib/libsample.so
	ldconfig
	unset LD_LIBRARY_PATH