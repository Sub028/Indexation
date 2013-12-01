#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "wavFile.h"
#include "Utility/dynamiqueIntegerTab.h"

int openWavFile(WavFile *wavFile, char *fileName, int dataOnly) {
	char nameBuffer[100];

	wavFile->fileName = (char*)malloc(sizeof(*fileName));
	strcpy(wavFile->fileName, fileName);
	wavFile->file = fopen(fileName, "rb");
	if(dataOnly) {
		fseek(wavFile->file, sizeof(WavHeader), SEEK_SET);
	} else {
		initWavHeader(&wavFile->wavHeader);
		readHeader(&wavFile->wavHeader, wavFile->file);
	}
	wavFile->dataOnly = dataOnly;
	initWavData(&wavFile->wavData);
	readWavData(&wavFile->wavData, wavFile->file);
}

int writeWavFile(WavFile *wavFile) {
	char buffer[100] = {0};
	FILE *fileResult;
	
	if(wavFile->dataOnly) {
		fileResult = fopen("Results/logs.txt", "a");
		fprintf(fileResult, "Attention ! on ne peut pas écrire un fichier en 'Data Only' \n");
		fclose(fileResult);
		return(0);
	}

	createPath(wavFile->fileName, "Results/", "_out.wav", buffer);
	fileResult = fopen(buffer, "wb");
	if(fileResult == NULL) {
		return(-1);
	}
	writeWavHeader(&wavFile->wavHeader, fileResult);
	writeWavData(&wavFile->wavData, fileResult);

	fclose(fileResult);
	return(0);
}

int writeWavHeaderFile(WavFile *wavFile) {
	char buffer[100] = {0};
	FILE *fileResult;
	
	if(wavFile->dataOnly) {
		fileResult = fopen("Results/logs.txt", "a");
		fprintf(fileResult, "Attention ! on ne peut pas écrire l'entête en 'Data Only' \n");
		fclose(fileResult);
		return(0);
	}

	createPath(wavFile->fileName, "Results/", "_header.txt", buffer);
	fileResult = fopen(buffer, "w");
	if(fileResult == NULL) {
		return(-1);
	}
	writeHeader(&wavFile->wavHeader, fileResult);
	
	fclose(fileResult);
	return(0);
}

int writeWavDataFile(WavFile *wavFile) {
	char buffer[100] = {0};
	FILE *fileResult;

	createPath(wavFile->fileName, "Results/", "_data.txt", buffer);
	fileResult = fopen(buffer, "w");
	if(fileResult == NULL) {
		return(-1);
	}
	writeData(&wavFile->wavData, fileResult);
	
	fclose(fileResult);
	return(0);
}

int writeWavNormalizedDataFile(WavFile *wavFile) {
	char buffer[100] = {0};
	FILE *fileResult;

	createPath(wavFile->fileName, "Results/", "_normalized_data.txt", buffer);
	fileResult = fopen(buffer, "w");
	if(fileResult == NULL) {
		return(-1);
	}
	writeNormalizedData(&wavFile->wavData, fileResult);

	fclose(fileResult);
	return(0);
}

//BOURRIN METHODE
int writeDescriptor(WavFile *wavFile) {
	char buffer[100] = {0};
	CelWavData *currentCel = wavFile->wavData.begin;
	DynamiqueIntegerTab *dynTab;
	FILE *fileResult;
	int nbWindows = 0;
	int i, j, k;
	float bar = 2.0 / NB_BARRE;
	float normalizedSample = 0;
	int rest;
	char id[100] = {0};

	srand(time(NULL));
	createPath(wavFile->fileName, "Results/", "_descriptor.txt", buffer);
	fileResult = fopen(buffer, "w");
	if(fileResult == NULL) {
		return(-1);
	}

	extractName(wavFile->fileName, buffer);
	sprintf(id, "%d", rand());
	strcat(id, buffer);
	nbWindows = wavFile->wavData.size / NB_ECH;
	if(wavFile->wavData.size % NB_ECH != 0) {
		nbWindows++;
	}
	
	fprintf(fileResult, "%s\t%d\t%d\t%d\n", id, NB_BARRE, NB_ECH, nbWindows);
	dynTab = (DynamiqueIntegerTab*)calloc(nbWindows, sizeof(DynamiqueIntegerTab));
	for(i = 0; i < nbWindows; i++) {
		initTab(&dynTab[i], NB_BARRE);
	}
	for(i = 0; i < nbWindows; i++) {
		for(j = 0; j < NB_ECH; j++) {
			for(k = -NB_BARRE / 2; k < NB_BARRE / 2; k++) {
				normalizedSample = currentCel->sample / pow(2, 15);
				if(normalizedSample >= bar * k && normalizedSample < bar * (k + 1)) {
					addValue(&dynTab[i], k + NB_BARRE / 2);
				}
			}
			if(currentCel->nextCell == NULL) {
				break;
			} else {
				currentCel = currentCel->nextCell;
			}
		}
	}
	for(i = 0; i < nbWindows; i++) {
		if(i != 0) {
			fprintf(fileResult, "\n");
		}
		writeTab(&dynTab[i], fileResult);
		freeIntegerTab(&dynTab[i]);
	}
	fclose(fileResult);
	return(0);
}

void closeWavFile(WavFile *wavFile) {
	freeDataWav(&wavFile->wavData);
	free(wavFile->fileName);
}
