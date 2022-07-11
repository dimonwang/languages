#!/bin/sh
set +x

EXEC="./main"
$EXEC &

PID=$(ps -ef | grep main | grep -v grep | awk '{print $2}')
sudo perf record -F 99 -p ${PID} -g -- sleep 60
sudo chown d:d perf.data
perf script -i perf.data > perf.unfold
./FlameGraph/stackcollapse-perf.pl perf.unfold > perf.folded
./FlameGraph/flamegraph.pl perf.folded > perf.svg

