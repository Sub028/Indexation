tst-text: main.o fonctions.o histogram.o
	gcc -o tst-text main.o fonctions.o histogram.o
	rm *.o

histogram.o: Sources/histogram.c Sources/histogram.h
	gcc -c Sources/histogram.c

fonctions.o: Sources/fonctions.c
	gcc -c Sources/fonctions.c

main.o: Sources/main.c
	gcc -c Sources/main.c
