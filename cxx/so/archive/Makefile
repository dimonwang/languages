.PHONY:all clean
all:
	g++ -fPIC -shared -o libsub.so sub.cc 
	g++ -c -o a.o a.cc
	ar -rcS liba.a a.o
	ranlib liba.a
	g++ -o main main.cc -L. -la -lsub

clean:
	rm -rf main main.o *.so main.dump
