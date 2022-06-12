.PHONY: all
all: build/dimon install/dimon clean/dimon build/main

build/dimon:
	gcc -o libdimon.so -fPIC -shared lib.c
build/main:
	gcc -o main main.c -ldimon
clean/dimon:
	rm -f libdimon.so
clean/main:
	rm -f main main.o
install/dimon:
	sudo cp libdimon.so /usr/lib/x86_64-linux-gnu/
	sudo cp lib.h /usr/include/libdimon.h
	sudo cp dimon.pc /usr/lib/x86_64-linux-gnu/pkgconfig
uninstall:
	sudo rm -f /usr/lib/x86_64-linux-gnu/libdimon.so /usr/include/libdimon.h /usr/lib/x86_64-linux-gnu/pkgconfig/dimon.pc
