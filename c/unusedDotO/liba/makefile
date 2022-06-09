.PHONY:all
all:
	gcc -o  a.o -c liba.c 
	gcc -o  b.o -c libb.c 
	ar rs libmya.a a.o b.o

clean:
	rm -rf *.o *.so *.a
