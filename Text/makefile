tst-text: indexation.o fonctions.o Histogram.o
	gcc -o tst-text indexation.o fonctions.o Histogram.o
	rm *.o

indexation.o: Sources/indexation.c
	gcc -c Sources/indexation.c

Histogram.o: Sources/Histogram.c Sources/Histogram.h
	gcc -c Sources/Histogram.c

fonctions.o: Sources/fonctions.c
	gcc -c Sources/fonctions.c
