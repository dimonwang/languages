#!/bin/sh

adb push libmyperfetto.so /vendor/lib64/
adb push libshared_funcs.so /vendor/lib64/
adb push test_no_instrument /vendor/bin/
adb push test_instrument /vendor/bin/
adb push symbols.txt /vendor/bin/
adb push symbol_flag.txt /vendor/bin/

adb wait-for-device shell "cd /vendor/bin/; ./test_instrument"
adb pull /vendor/bin/example.pftrace ./
