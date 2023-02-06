.PHONY:all clean


all:
	g++ -o test.o -c test.cc
	g++ -o test_2.o -c test_2.cc
	g++ -o main.o -c main.cc
	g++ -o main main.o test.o test_2.o

clean:
	rm -rf *.o main
