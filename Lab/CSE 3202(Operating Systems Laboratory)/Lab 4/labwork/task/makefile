app: main.o mod_1.o mod_2.o mod_3.o mod_4.o 
	cc -o app main.o mod_1.o mod_2.o mod_3.o mod_4.o

main.o: main.c inc_1.h inc_2.h inc_3.h inc_4.h
	cc -c main.c 

mod_1.o: mod_1.c inc_1.h
	cc -c mod_1.c

mod_2.o: mod_2.c inc_2.h 
	cc -c mod_2.c

mod_3.o: mod_3.c inc_3.h
	cc -c mod_3.c

mod_4.o: mod_4.c inc_4.h
	cc -c mod_4.c

 
