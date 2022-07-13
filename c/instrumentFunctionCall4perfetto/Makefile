.PHONY: all clean
cc:=~/NDK/android-ndk-r24/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android26-clang
cpp:=~/NDK/android-ndk-r24/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android26-clang++
#cc:=gcc
#cpp:=g++
all:
	$(cpp) -shared -fPIC -std=c++17 -o libperfetto.so perfetto.cc
	$(cc) -c -g -std=c17 -finstrument-functions -o  test.o test.c
	$(cpp) -c -g -std=c++17 -o  instrument.o instrument.cc
	$(cpp) -o test test.o instrument.o -L. -lperfetto

clean:
	rm -rf test *.o a.out instrument.log perfetto.o libperfetto.so
