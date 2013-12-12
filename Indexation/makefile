Indexation: Objects/indexation.o Objects/wavFile.o Objects/wavData.o Objects/wavHeader.o Objects/dynamicIntegerTab.o Objects/utility.o
	mkdir Objects
	mv *.o Objects
	gcc -o Indexation Objects/indexation.o Objects/wavFile.o Objects/wavData.o Objects/wavHeader.o Objects/dynamicIntegerTab.o Objects/utility.o

Objects/indexation.o: Sources/indexation.c
	gcc -c Sources/indexation.c

Objects/wavHeader.o: Sources/Sound/wavHeader.c Sources/Sound/wavHeader.h
	gcc -c Sources/Sound/wavHeader.c

Objects/wavData.o: Sources/Sound/wavData.c Sources/Sound/wavData.h
	gcc -c Sources/Sound/wavData.c

Objects/wavFile.o: Sources/Sound/wavFile.c Sources/Sound/wavFile.h
	gcc -c Sources/Sound/wavFile.c

Objects/dynamicIntegerTab.o: Sources/Sound/Utility/dynamicIntegerTab.c Sources/Sound/Utility//dynamicIntegerTab.h
	gcc -c Sources/Utility/dynamicIntegerTab.c
	
Objects/utility.o: Sources/Sound/Utility/utility.c Sources/Sound/Utility/utility.h
	gcc -c Sources/Utility/utility.c
