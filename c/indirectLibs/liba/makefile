.PHONY:all
all:
	gcc -o  a.o -c liba.c -I../lib2 -L../lib2
	ar rs libmya.a a.o

clean:
	rm -rf *.o *.so *.a
