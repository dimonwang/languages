.PHONY:all clean
all:
	gcc -E subst.c
	gcc -o test.o -c test.c
	gcc -o main main.c test.o
clean:
	echo "done"
	rm -f test.o main main.o
