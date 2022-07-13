.PHONY: all clean
cc:=~/NDK/android-ndk-r24/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android30-clang
cpp:=~/NDK/android-ndk-r24/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android30-clang++
#cc:=gcc
#cpp:=g++
all:
	$(cpp) -shared -fpic -std=c++11 -o libperfetto.so perfetto.cc
	$(cpp) -c -g -std=c++11 -finstrument-functions -fno-emulated-tls -o instrument.o instrument.cc
	$(cc) -c -g -std=c11 -finstrument-functions -o  test.o test.c
	$(cpp) -o test test.o instrument.o -L. -lperfetto -llog -pthread

clean:
	rm -rf test *.o a.out instrument.log perfetto.o libperfetto.so
