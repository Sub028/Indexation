Indexation: indexation.o wavFile.o wavData.o wavHeader.o dynamicIntegerTab.o utility.o openPicture.o picture.o matrix.o histogram.o quantification.o 
	gcc -o Indexation indexation.o wavFile.o wavData.o wavHeader.o dynamicIntegerTab.o utility.o openPicture.o picture.o matrix.o histogram.o quantification.o -lm

indexation.o: Sources/indexation.c
	gcc -c Sources/indexation.c

wavHeader.o: Sources/Sound/wavHeader.c Sources/Sound/wavHeader.h
	gcc -c Sources/Sound/wavHeader.c

wavData.o: Sources/Sound/wavData.c Sources/Sound/wavData.h
	gcc -c Sources/Sound/wavData.c

wavFile.o: Sources/Sound/wavFile.c Sources/Sound/wavFile.h
	gcc -c Sources/Sound/wavFile.c



dynamicIntegerTab.o: Sources/Utility/dynamicIntegerTab.c Sources/Sound/Utility/dynamicIntegerTab.h
	gcc -c Sources/Utility/dynamicIntegerTab.c
	
utility.o: Sources/Utility/utility.c Sources/Sound/Utility/utility.h
	gcc -c Sources/Utility/utility.c



openPicture.o: Sources/Picture/openPicture.c Sources/Picture/openPicture.h
	gcc -c Sources/Picture/openPicture.c

picture.o: Sources/Picture/picture.c Sources/Picture/picture.h Sources/Picture/matrix.h
	gcc -c Sources/Picture/picture.c

matrix.o: Sources/Picture/matrix.c Sources/Picture/matrix.h Sources/Picture/picture.h
	gcc -c Sources/Picture/matrix.c

histogram.o: Sources/Picture/histogram.c Sources/Picture/histogram.h Sources/Picture/matrix.h
	gcc -c Sources/Picture/histogram.c

quantification.o: Sources/Picture/quantification.c Sources/Picture/quantification.h
	gcc -c Sources/Picture/quantification.c



clear: 
	rm *.o
	rm -r Bases
	rm log.log