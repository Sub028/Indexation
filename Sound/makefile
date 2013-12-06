tst-son: main.o wavFile.o wavData.o wavHeader.o dynamiqueIntegerTab.o utility.o
	gcc -o tst-son main.o wavHeader.o wavData.o wavFile.o dynamiqueIntegerTab.o utility.o
	rm *.o
	mv tst-son Executable

wavHeader.o: Sources/wavHeader.c Sources/wavHeader.h
	gcc -c Sources/wavHeader.c

wavData.o: Sources/wavData.c Sources/wavData.h
	gcc -c Sources/wavData.c

wavFile.o: Sources/wavFile.c Sources/wavFile.h
	gcc -c Sources/wavFile.c

dynamiqueIntegerTab.o: Sources/Utility/dynamiqueIntegerTab.c Sources/Utility//dynamiqueIntegerTab.h
	gcc -c Sources/Utility/dynamiqueIntegerTab.c
	
utility.o: Sources/Utility/utility.c Sources/Utility/utility.h
	gcc -c  Sources/Utility/utility.c

main.o: Sources/main.c
	gcc -c Sources/main.c