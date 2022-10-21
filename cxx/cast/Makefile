.PHONY:all clean
all:
	g++ -o main main.cc
	g++ -o main_basic main_basic.cc
	objdump -d main > main.dump

clean:
	rm -rf main main.o main.dump main_basic main_basic.o
