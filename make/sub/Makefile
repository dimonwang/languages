.PHONY: all
all: sub2
	gcc -c sub.c -I./sub2/
sub2:
	make -C sub2/
graph:
	make graph -C sub2/
	makefile2graph -B > dimon.dot
clean:
	rm -f *.o *.dot
	make clean -C sub2/
