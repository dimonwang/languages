.PHONY:all clean
all:
	gcc -fPIC -shared -o liba.so a.c -Wl,-znodlopen
	g++ -o main main.cc -ldl
	# objdump -d main > main.dump

clean:
	rm -rf main main.o *.so main.dump
