.PHONY:all clean


all:
	gcc -o test.o -c test.c
	g++ -o main.o -c main.cc
	g++ -o main main.o test.o

clean:
	rm -rf *.o main
