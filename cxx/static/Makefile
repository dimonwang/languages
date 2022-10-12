.PHONY:all clean
all:
	g++ -c -o main.o main.cc
	g++ -c -o c.o c.cc
	g++ -c -o mytest.o mytest.cc
	g++ -o main main.o c.o mytest.o
	# objdump -d main > main.dump

clean:
	rm -rf main main.o main.dump c.o mytest.o
