tst-text: main.o histogram.o parser.o
	gcc -o tst-text main.o histogram.o parser.o
	rm *.o

histogram.o: Sources/histogram.c Sources/histogram.h
	gcc -c Sources/histogram.c

main.o: Sources/main.c
	gcc -c Sources/main.c

parser.o: Sources/parser.c Sources/parser.h
	gcc -c Sources/parser.c

clean:
	rm *.o	
