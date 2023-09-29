

main.o: main.c inc_a.h inc_b.h
	cc -c main.c 

mod_a.o: mod_a.c inc_a.h
	cc -c mod_a.c

mod_b.o: mod_b.c inc_b.h 
	cc -c mod_b.c
	
target: main.o mod_a.o mod_b.o 
	cc -o target main.o mod_a.o mod_b.o


 
