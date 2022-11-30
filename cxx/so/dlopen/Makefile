.PHONY:all clean
all:
	g++ -fPIC -shared -o liba.so a.cc
	g++ -o main main.cc -ldl
	g++ -o main_repeat main_repeat.cc -ldl
	# objdump -d main > main.dump

clean:
	rm -rf main main_repeat main_repeat.o main.o *.so main.dump
