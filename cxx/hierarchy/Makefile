.PHONY:all clean
all:
	g++ -o main main.cc
	g++ -o main_protected main_protected.cc
	objdump -d main > main.dump

clean:
	rm -rf main main.o main.dump main_protected main_protected.o
