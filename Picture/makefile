execute: matrix.o openPicture.o histogram.o quantification.o main.o
	gcc -o execute openPicture.o matrix.o histogram.o quantification.o main.o -lm
	rm *.o

openPicture.o: Source/openPicture.c Source/openPicture.h Source/matrix.h
	gcc -c Source/openPicture.c
	
matrix.o: Source/matrix.c Source/matrix.h Source/picture.h
	gcc -c Source/matrix.c

histogram.o: Source/histogram.c Source/histogram.h Source/matrix.h
	gcc -c Source/histogram.c

quantification.o: Source/quantification.c Source/quantification.h
	gcc -c Source/quantification.c

main.o: Source/main.c Source/openPicture.h
	gcc -c Source/main.c

clear: 
	rm *.o