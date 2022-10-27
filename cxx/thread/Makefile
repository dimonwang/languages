.PHONY:all clean
all:
	g++ -g -o main main.cc -pthread
	objdump -d main > main.dump

clean:
	rm -rf main main.o main.dump
