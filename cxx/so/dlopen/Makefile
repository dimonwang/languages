.PHONY:all clean
all:
	g++ -fPIC -shared -o liba.so a.cc
	g++ -o main main.cc -ldl
	g++ -o main_repeat main_repeat.cc -ldl
	g++ -o main_repeat_in_thread main_repeat_in_thread.cc -ldl -pthread
	# objdump -d main > main.dump

clean:
	rm -rf main main_repeat main_repeat.o main_repeat_in_thread main_repeat_in_thread.o main.o *.so main.dump
