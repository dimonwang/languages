.PHONY: all clean
all:
	gcc -c -g -finstrument-functions -o  test.o test.c
	gcc -c -g -finstrument-functions -o  instrument.o instrument.c
	gcc -g -o test test.o instrument.o

clean:
	rm -rf test *.o a.out instrument.log
