.PHONY:all clean
all:
	g++ -shared -fpic -o libashiba.so test.cc
	g++ -o ashiba.o -c test.cc
	ar rs libashiba.a ashiba.o
	g++ -o main.o -c main.cc
	g++ -o main_default main.o -L. -lashiba
	g++ -static -o main_static main.o -L. -lashiba

clean:
	rm -f *.o *.so *.a main_default main_static
