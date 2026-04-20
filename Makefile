ll: programma

programma: main.o segnalazioni.o
	gcc main.o segnalazioni.o -o programma

main.o: main.c segnalazioni.h
	gcc -c main.c

segnalazioni.o: segnalazioni.c segnalazioni.h
	gcc -c segnalazioni.c

clean:
	rm -f *.o programma