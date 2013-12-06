Indexation: indexation.o wavFile.o wavData.o wavHeader.o dynamiqueIntegerTab.o utility.o
	gcc -o Indexation indexation.o wavFile.o wavData.o wavHeader.o dynamiqueIntegerTab.o utility.o
	rm *.o


indexation.o: Sources/indexation.c
	gcc -c Sources/indexation.c


	
wavHeader.o: Sources/Sound/wavHeader.c Sources/Sound/wavHeader.h
	gcc -c Sources/Sound/wavHeader.c

wavData.o: Sources/Sound/wavData.c Sources/Sound/wavData.h
	gcc -c Sources/Sound/wavData.c

wavFile.o: Sources/Sound/wavFile.c Sources/Sound/wavFile.h
	gcc -c Sources/Sound/wavFile.c

dynamiqueIntegerTab.o: Sources/Sound/Utility/dynamiqueIntegerTab.c Sources/Sound/Utility//dynamiqueIntegerTab.h
	gcc -c Sources/Utility/dynamiqueIntegerTab.c
	
utility.o: Sources/Sound/Utility/utility.c Sources/Sound/Utility/utility.h
	gcc -c Sources/Utility/utility.c
