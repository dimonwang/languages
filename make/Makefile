all: sub
	gcc -o main.o -c main.c -I./sub/ 
	gcc -o main main.o ./sub/sub.o ./sub/sub2/sub2.o
sub:
	make -C sub/
graph:
	make graph -C sub/
	makefile2graph -B > dimon.dot
clean:
	rm -f main main.o *.dot *.png
	make clean -C sub/
