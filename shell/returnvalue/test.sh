#!/bin/sh

if [ $# -lt 2 ]; then 
	echo "please enter the return value. current:" $#
	exit
fi

exit $1
