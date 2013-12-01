#include <stdio.h>
#include <stdlib.h>
#include "wavFile.h"

int main(int argc, char *argv[]) {
	if(argc < 2) {
		fprintf(stderr, "Nom du fichier est requis\n");
		return(EXIT_FAILURE);
	}

	WavFile wavFile;
	openWavFile(&wavFile, argv[1]);

	writeWavFile(&wavFile);
	writeWavHeaderFile(&wavFile);
	writeWavDataFile(&wavFile);
	writeWavNormalizedDataFile(&wavFile);

	writeDescriptor(&wavFile);
	closeWavFile(&wavFile);

	return(EXIT_SUCCESS);
}