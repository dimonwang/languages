.PHONY: all clean 
all:
	gcc -o main.o -c main.c
	gcc -o main main.o
	gcc -rdynamic -o rmain main.o

clean:
	rm -f *.o main rmain
