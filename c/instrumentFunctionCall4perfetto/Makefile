.PHONY: all clean
build:=~/NDK/android-ndk-r24/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android21-clang
#build:=gcc
all:
	$(build) -c -g -finstrument-functions -o  test.o test.c
	$(build) -c -g -finstrument-functions -o  instrument.o instrument.c
	$(build) -g -o test test.o instrument.o

clean:
	rm -rf test *.o a.out instrument.log
