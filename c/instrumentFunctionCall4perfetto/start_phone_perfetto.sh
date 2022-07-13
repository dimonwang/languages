#!/bin/sh


adb shell setprop persist.traced.enable 1

if [ ! -e record_android_trace ]; then
curl -O https://raw.githubusercontent.com/google/perfetto/master/tools/record_android_trace
chmod u+x record_android_trace
fi

./record_android_trace -o trace_file.perfetto-trace -t 10s -b 32mb sched freq idle am vm gfx view binder_driver hal dalvik camera input res memory
