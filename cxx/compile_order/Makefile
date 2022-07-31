.PHONY:all clean
all:
	g++ -o test.o -c test.cc
	g++ -o main.o -c main.cc
	g++ -o main_test main.o test.o
	g++ -o test_main test.o main.o


clean:
	rm -rf main1 main2 *.o main main_test test_main
