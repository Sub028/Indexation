tst-son: main.o wavFile.o wavData.o wavHeader.o dynamicIntegerTab.o utility.o
	gcc -o tst-son main.o wavHeader.o wavData.o wavFile.o dynamicIntegerTab.o utility.o
	rm *.o

wavHeader.o: Sources/wavHeader.c Sources/wavHeader.h
	gcc -c Sources/wavHeader.c

wavData.o: Sources/wavData.c Sources/wavData.h
	gcc -c Sources/wavData.c

wavFile.o: Sources/wavFile.c Sources/wavFile.h
	gcc -c Sources/wavFile.c

dynamicIntegerTab.o: Sources/Utility/dynamicIntegerTab.c Sources/Utility//dynamicIntegerTab.h
	gcc -c Sources/Utility/dynamicIntegerTab.c
	
utility.o: Sources/Utility/utility.c Sources/Utility/utility.h
	gcc -c  Sources/Utility/utility.c

main.o: Sources/main.c
	gcc -c Sources/main.c