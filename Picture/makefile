tst-img: matrix.o openPicture.o histogram.o quantification.o main.o utility.o
	gcc -o tst-img openPicture.o matrix.o histogram.o quantification.o main.o utility.o -lm
	rm *.o

openPicture.o: Sources/openPicture.c Sources/openPicture.h Sources/matrix.h
	gcc -c Sources/openPicture.c
	
matrix.o: Sources/matrix.c Sources/matrix.h Sources/picture.h
	gcc -c Sources/matrix.c

histogram.o: Sources/histogram.c Sources/histogram.h Sources/matrix.h
	gcc -c Sources/histogram.c

quantification.o: Sources/quantification.c Sources/quantification.h
	gcc -c Sources/quantification.c

main.o: Sources/main.c Sources/openPicture.h
	gcc -c Sources/main.c
	
utility.o: Sources/Utility/utility.c Sources/Utility/utility.h
	gcc -c Sources/Utility/utility.c

clear: 
	rm *.o