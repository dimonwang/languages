.PHONY: all clean
build_tool_path:=~/NDK/android-ndk-r24/toolchains/llvm/prebuilt/linux-x86_64/bin/
cc:=$(build_tool_path)/aarch64-linux-android30-clang
cpp:=$(build_tool_path)/aarch64-linux-android30-clang++
cmd_readelf:=$(build_tool_path)/llvm-readelf
host_cc:=gcc
host_cpp:=g++
all: inst no_inst
myperfetto:
	$(cpp) -shared -fpic -std=c++11 -o libmyperfetto.so perfetto.cc

inst:
	$(cpp) -c -g -std=c++11 -fno-emulated-tls -o instrument.o instrument.cc
	$(cc) -c -g -std=c11 -finstrument-functions -fno-emulated-tls -o  test_instrument.o test_instrument.c
	$(cpp) -o test_instrument test_instrument.o instrument.o -L. -lmyperfetto -llog -pthread
	$(cmd_readelf) -s test_instrument | awk '{if ($$4 == "FUNC" && $$7 != "UND") print $$2,$$8}' > symbols.txt
	$(cmd_readelf) -s test_instrument | grep -F 'd123456789flg' | awk '{print $$2,$$8}' > symbol_flag.txt

no_inst: 
	$(cpp) -c -g -std=c++11 -fno-emulated-tls -o test_no_instrument.o test_no_instrument.cc
	$(cpp) -o test_no_instrument test_no_instrument.o -L. -lmyperfetto -llog -pthread

host:
	$(host_cc) -c -o host_instrument.o host_instrument.c
	$(host_cc) -c -g -finstrument-functions -o host_test_instrument.o host_test_instrument.c
	$(host_cc) -o host_test host_instrument.o host_test_instrument.o

clean:
	rm -rf test_instrument test_no_instrument *.o a.out instrument.log perfetto.o trace_file.perfetto-trace example.pftrace host_test symbols.txt symbol_flag.txt
