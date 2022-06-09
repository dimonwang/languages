.PHONY:all clean
all:
	make -C lib2
	make -C lib1
	make -C liba
	gcc -o main main.c -lmy1 -lmy2 -I./lib1/ -L./lib1/ -L./lib2/
	gcc -o main_static main_static.c -lmya -lmy2 -I./liba/ -L./lib2/ -L./liba/

clean:
	rm -f *.o main main_static
	make -C lib1 clean
	make -C lib2 clean
	make -C liba clean

