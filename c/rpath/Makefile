.PHONY: all clean
all:
	gcc -shared -fpic -g -o libtest2.so test2.c
	gcc -shared -fpic -g -Wl,-e,main -o libtest.so test.c -L. -ltest2
	gcc -o main main.c -Wl,--rpath-link=. -L. -ltest

clean:
	rm -f *.o *.so main
