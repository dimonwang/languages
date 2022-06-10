.PHONY: all clean
all:
	g++ -o cppCaller.o -c cppCaller.cpp
	g++ -o cppCallerWrapper.o -c cppCallerWrapper.cpp
	gcc -o main.o -c main.c
	g++ -o main main.o cppCaller.o cppCallerWrapper.o
clean:
	rm -rf *.o main
