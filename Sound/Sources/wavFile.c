//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: ERDELYI Jean-François
// Date de création: 01/12/13
//======================================================================//
// Fichier C: wavFile.c ou Fichier H: wavFile.h
//======================================================================//
// Module AUDIO :
// - Permet de manipuler des fichiers wav
//======================================================================//

/**
 * \file wavFile.c
 * \author Jean-François Erdelyi
 * \brief Permet de manipuler des fichiers wav.
 * \version 1
 * \date 01 decembre 2013.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "wavFile.h"

/**
 * \fn int openWavFile(WavFile *wavFile, char *fileName, int dataOnly)
 * \brief Ouvre un fichier wav et le met en mémoire
 *
 * \param wavFile Fichier wav en mémoire.
 * \param fileName Nom du fichier wav.
 */
void openWavFile(WavFile *wavFile, char *fileName) {
	char nameBuffer[BUFFER_SIZE];

	wavFile->fileName = (char*)malloc(sizeof(*fileName));
	strcpy(wavFile->fileName, fileName);
	wavFile->file = fopen(fileName, "rb");

	initWavHeader(&wavFile->wavHeader);
	readHeader(&wavFile->wavHeader, wavFile->file);
	initWavData(&wavFile->wavData);
	readWavData(&wavFile->wavData, wavFile->file);
}

/**
 * \fn int writeWavFile(WavFile *wavFile)
 * \brief Ecrit un fichier wav en binaire.
 *
 * \param wavFile Fichier wav en mémoire.
 * \return -1 si une erreur lors de l'ouverture sinon 0.
 */
int writeWavFile(WavFile *wavFile) {
	char buffer[BUFFER_SIZE] = {0};
	FILE *fileResult;

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

/**
 * \fn int writeWavHeaderFile(WavFile *wavFile) 
 * \brief Ecrit l'header dans un fichier texte.
 *
 * \param wavFile Fichier wav en mémoire.
 * \return -1 si une erreur lors de l'ouverture sinon 0.
 */
int writeWavHeaderFile(WavFile *wavFile) {
	char buffer[BUFFER_SIZE] = {0};
	FILE *fileResult;

	createPath(wavFile->fileName, "Results/", "_header.txt", buffer);
	fileResult = fopen(buffer, "w");
	if(fileResult == NULL) {
		return(-1);
	}
	writeHeader(&wavFile->wavHeader, fileResult);
	
	fclose(fileResult);
	return(0);
}

/**
 * \fn int writeWavDataFile(WavFile *wavFile)
 * \brief Ecrit les data dans un fichier texte.
 *
 * \param wavFile Fichier wav en mémoire.
 * \return -1 si une erreur lors de l'ouverture sinon 0.
 */
int writeWavDataFile(WavFile *wavFile) {
	char buffer[BUFFER_SIZE] = {0};
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

/**
 * \fn int writeWavNormalizedDataFile(WavFile *wavFile)
 * \brief Ecrit les data normalisé dans un fichier texte.
 *
 * \param wavFile Fichier wav en mémoire.
 * \return -1 si une erreur lors de l'ouverture sinon 0.
 */
int writeWavNormalizedDataFile(WavFile *wavFile) {
	char buffer[BUFFER_SIZE] = {0};
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

/**
 * \fn int writeDescriptor(WavFile *wavFile, FILE *descriptorBase, FILE *log)
 * \brief Ecrit le descipteur de donnée
 *
 * \param wavFile Fichier wav en mémoire.
 * \param descriptorBase Bases des descripteur audio.
 * \return -1 si une erreur lors de l'ouverture sinon 0.
 */
int writeDescriptor(WavFile *wavFile, FILE *descriptorBase, FILE *log) {
	struct stat st;
	char buffer[BUFFER_SIZE] = {0};
	char id[BUFFER_SIZE] = {0};
	int nbWindows = 0;
	int i, j, k;
	int nbBar, nbSample;
	float bar;
	float normalizedSample = 0;
	CelWavData *currentCel = wavFile->wavData.begin;
	HistogramSound *dynTab;
	FILE *soundBase = fopen("Bases/base_descripteur_audio.base", "a");

// 	srand(time(NULL));
	if(stat(wavFile->fileName, &st) == -1) {
		fprintf(log, "STAT ERROR ");
		return(-1);
	}
	if(getValueOf("NB_BAR", &nbBar) == -1 || getValueOf("NB_SAMPLE", &nbSample) == -1) {
		fprintf(log, "CONFIG ERROR ");
		return(-1);
	}

	bar = 2.0 / nbBar;
	sprintf(id, "ID%d", rand());
	strcat(id, wavFile->fileName);
	nbWindows = wavFile->wavData.size / nbSample;
	if(wavFile->wavData.size % nbSample != 0) {
		nbWindows++;
	}

	fprintf(soundBase, "%s\t%d\t%d\t%s\t%s", id, nbBar, nbWindows, "sound", ctime(&st.st_mtime));
	dynTab = (HistogramSound*)calloc(nbWindows, sizeof(HistogramSound));
	for(i = 0; i < nbWindows; i++) {
		initTab(&dynTab[i], nbBar);
	}
	for(i = 0; i < nbWindows; i++) {
		for(j = 0; j < nbSample; j++) {
			for(k = -nbBar / 2; k < nbBar / 2; k++) {
				normalizedSample = currentCel->sample / pow(2, 15);
				if(normalizedSample >= bar * k && normalizedSample < bar * (k + 1)) {
					addValue(&dynTab[i], k + nbBar / 2);
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
			fprintf(soundBase, "\n");
		}
		writeTab(&dynTab[i], soundBase);
		freeIntegerTab(&dynTab[i]);
	}
	fprintf(soundBase, "\n");
	fprintf(descriptorBase, "%s\t%s\n", wavFile->fileName, id);
	fclose(soundBase);
	return(0);
}

/**
 * \fn void closeWavFile(WavFile *wavFile)
 * \brief Ferme le fichier en mémoire libere les allocations
 *
 * \param wavFile Fichier wav en mémoire.
 */
void closeWavFile(WavFile *wavFile) {
	freeDataWav(&wavFile->wavData);
	free(wavFile->fileName);
}
