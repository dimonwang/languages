.PHONY: all clean
cc:=~/NDK/android-ndk-r24/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android30-clang
cpp:=~/NDK/android-ndk-r24/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android30-clang++
#cc:=gcc
#cpp:=g++
all: inst no_inst
myperfetto:
	$(cpp) -shared -fpic -std=c++11 -o libmyperfetto.so perfetto.cc

inst:
	$(cpp) -c -g -std=c++11 -fno-emulated-tls -o instrument.o instrument.cc
	$(cc) -c -g -std=c11 -finstrument-functions -fno-emulated-tls -o  test_instrument.o test_instrument.c
	$(cpp) -o test_instrument test_instrument.o instrument.o -L. -lmyperfetto -llog -pthread

no_inst: 
	$(cpp) -c -g -std=c++11 -fno-emulated-tls -o test_no_instrument.o test_no_instrument.cc
	$(cpp) -o test_no_instrument test_no_instrument.o -L. -lmyperfetto -llog -pthread

clean:
	rm -rf test_instrument test_no_instrument *.o a.out instrument.log perfetto.o trace_file.perfetto-trace
