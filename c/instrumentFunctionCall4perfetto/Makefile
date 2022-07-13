.PHONY: all clean
cc:=~/NDK/android-ndk-r14b/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android21-clang
cpp:=~/NDK/android-ndk-r14b/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android21-clang++
#cc:=gcc
#cpp:=g++
all:
	$(cpp) -shared -fPIC perfetto.cc -o libperfetto.so
	$(cc) -c -g -finstrument-functions -o  test.o test.c
	$(cc) -c -g -finstrument-functions -o  instrument.o instrument.c
	$(cc) -g -o test test.o instrument.o

clean:
	rm -rf test *.o a.out instrument.log
