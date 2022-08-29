.PHONY:all clean
all:
	g++ -c -o test.o test.cc
	gcc -c -o main.o main.c
	g++ -o main main.o test.o

clean:
	rm -rf *.o main
