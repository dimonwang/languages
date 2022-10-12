.PHONY:all clean
all:
	g++ -fPIC -shared -o libsub1.so sub1.cc 
	g++ -fPIC -shared -o libsub2.so sub2.cc 
	g++ -fPIC -shared -o liba.so a.cc -L. -lsub2
	# g++ -fPIC -shared -o liba.so a.cc 
	g++ -fPIC -shared -o libb.so b.cc -L. -lsub1
	# g++ -fPIC -shared -o libb.so b.cc 
	LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH g++ -o main main.cc -L. -la -lb -lsub1 -lsub2
	# objdump -d main > main.dump

clean:
	rm -rf main main.o *.so main.dump
