.PHONY:all clean
all:
	g++ -fPIC -shared -o liba.so a.cc
	g++ -o main main.cc -ldl
	# objdump -d main > main.dump

clean:
	rm -rf main main.o *.so main.dump
