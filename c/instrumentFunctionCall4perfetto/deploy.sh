#!/bin/sh

adb push libmyperfetto.so /system/lib64/
adb push test /system/bin/

adb wait-for-device shell "cd /system/bin/; ./test"
