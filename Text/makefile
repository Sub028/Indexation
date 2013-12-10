tst-text: indexation.o fonctions.o Histogram.o
	gcc -o tst-text indexation.o fonctions.o histogram.o
	rm *.o

histogram.o: Sources/histogram.c Sources/histogram.h
	gcc -c Sources/histogram.c

main.o: Sources/main.c
	gcc -c Sources/main.c
