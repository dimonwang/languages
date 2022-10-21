.PHONY:all clean
all:
	g++ -o main main.cc
	g++ -o main_cost main_cost.cc
	g++ -o main_exception_spec main_exception_spec.cc
	# objdump -d main > main.dump

clean:
	rm -rf main main.o main.dump main_cost.dump main_cost.o main_cost main_exception_spec
