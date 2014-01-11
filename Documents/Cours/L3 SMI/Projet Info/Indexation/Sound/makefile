tst-son: main.o wavFile.o wavData.o wavHeader.o histogramSound.o utility.o
	gcc -o tst-son main.o wavHeader.o wavData.o wavFile.o histogramSound.o utility.o
	rm *.o

wavHeader.o: Sources/wavHeader.c Sources/wavHeader.h
	gcc -c Sources/wavHeader.c

wavData.o: Sources/wavData.c Sources/wavData.h
	gcc -c Sources/wavData.c

wavFile.o: Sources/wavFile.c Sources/wavFile.h
	gcc -c Sources/wavFile.c

histogramSound.o: Sources/histogramSound.c Sources/histogramSound.h
	gcc -c Sources/histogramSound.c
	
utility.o: Sources/Utility/utility.c Sources/Utility/utility.h
	gcc -c  Sources/Utility/utility.c

main.o: Sources/main.c
	gcc -c Sources/main.c
	
clear: 
	rm *.o