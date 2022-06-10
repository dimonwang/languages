.PHONY:all clean
all:
	make -C liba
	## do not link unused .o
	gcc -o main main.c -lmya -I./liba/ -L./liba/
	## force all the .o in archive to be linked in.
	gcc -o main1 main.c -Wl,--whole-archive -lmya -Wl,--no-whole-archive -I./liba/ -L./liba/ 

clean:
	rm -f *.o main main1
	make -C liba clean

