#!/bin/sh

adb push libmyperfetto.so /system/lib64/
adb push test_no_instrument /system/bin/
adb push test_instrument /system/bin/

#adb wait-for-device shell "cd /system/bin/; ./test_no_instrument"
