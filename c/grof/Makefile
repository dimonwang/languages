.PHONY: all clean 
all:
	gcc -o main main.c
	gcc -finstrument-functions -o main_instrument main.c
	gcc -finstrument-functions -pg -o main_instrument_gprof main.c
	objdump -d main_instrument > main_instrument.dmp
	objdump -d main_instrument_gprof > main_instrument_gprof.dmp

clean:
	rm -f *.o main main_instrument main_instrument_gprof *.dmp gmon.out
