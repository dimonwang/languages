.PHONY:all clean
all:
	make -C liba
	gcc -o main main.c -lmya -I./liba/ -L./liba/

clean:
	rm -f *.o main
	make -C liba clean

