#ifndef WAVE_FILE_H
#define WAVE_FILE_H

#include "wavHeader.h"
#include "wavData.h"
#include "utility.h"

//TODO : NIOURF !!! Utiliser le fichier de conf !!!
#define NB_BARRE 30	//Nombre de barre
#define NB_ECH 1024	//Nombre d'échantillon (de points par intervalle)
			//Nombre de fenetre NBFEN = SON / NB_ECH;

typedef struct WavFile {
	FILE *file;
	char *fileName;
	int dataOnly;
	WavHeader wavHeader;
	WavData wavData;
} WavFile;

int openWavFile(WavFile *wavFile, char *fileName, int dataOnly);
int writeWavFile(WavFile *wavFile);
int writeWavHeaderFile(WavFile *wavFile);
int writeWavDataFile(WavFile *wavFile);
int writeWavNormalizedDataFile(WavFile *wavFile);
int writeDescriptor(WavFile *wavFile);
void closeWavFile(WavFile *wavFile);

#endif /*WAVE_FILE_H*/