#!/bin/sh

git clone https://github.com/brendangregg/FlameGraph.git
sudo apt-get install linux-tools-"$(uname -r)"
