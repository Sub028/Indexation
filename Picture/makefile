tst-img: matrix.o picture.o openPicture.o histogram.o quantification.o main.o utility.o
	gcc -o tst-img picture.o openPicture.o matrix.o histogram.o quantification.o main.o utility.o -lm
	rm *.o

openFold: openFolder.o matrix.o picture.o openPicture.o histogram.o quantification.o utility.o
	gcc -o openFold openFolder.o picture.o openPicture.o matrix.o histogram.o quantification.o utility.o -lm
	rm *.o

picture.o: Sources/picture.c Sources/picture.h Sources/matrix.h
	gcc -c Sources/picture.c

openPicture.o: Sources/openPicture.c Sources/openPicture.h Sources/matrix.h
	gcc -c Sources/openPicture.c
	
matrix.o: Sources/matrix.c Sources/matrix.h
	gcc -c Sources/matrix.c

histogram.o: Sources/histogram.c Sources/histogram.h Sources/matrix.h
	gcc -c Sources/histogram.c

quantification.o: Sources/quantification.c Sources/quantification.h
	gcc -c Sources/quantification.c

main.o: Sources/main.c Sources/openPicture.h
	gcc -c Sources/main.c
	
utility.o: Sources/Utility/utility.c Sources/Utility/utility.h
	gcc -c Sources/Utility/utility.c

openFolder.o: Sources/openFolder.c
	gcc -c Sources/openFolder.c

clear: 
	rm *.o