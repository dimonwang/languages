.PHONY:all clean
all:
	gcc -g -o provider provider.c -lrt -lpthread
	gcc -g -o consumer consumer.c -lrt -lpthread

clean:
	rm -rf provider consumer provider.o consumer.o
