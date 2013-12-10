indexation: indexation.o fonctions.o Histogram.o
	gcc -o indexation indexation.o fonctions.o Histogram.o

indexation.o: indexation.c
	gcc -c indexation.c

Histogram.o: Histogram.c Histogram.h
	gcc -c Histogram.c

fonctions.o: fonctions.c
	gcc -c fonctions.c
