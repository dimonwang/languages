.PHONY: all clean
all:
	gcc -shared -fpic -g -Wl,-e,main -o libtest.so test.c

clean:
	rm -f *.o *.so main
