/**
 * \file wavFile.h
 * \author Jean-François Erdelyi
 * \brief Permet de manipuler des fichiers wav.
 * \version 1
 * \date 01 decembre 2013.
 */

#ifndef WAVE_FILE_H
#define WAVE_FILE_H

#include "wavHeader.h"
#include "wavData.h"
#include "Utility/utility.h"

/**
 * \struct WavFile
 * \brief Représentation d'un fichier wav en mémoire
 *
 * Le fichier binaire, le nom complet du fichier puis l'header et les données
 */
typedef struct WavFile {
	FILE *file;
	char *fileName;
	WavHeader wavHeader;
	WavData wavData;
} WavFile;

void openWavFile(WavFile *wavFile, char *fileName);
int writeWavFile(WavFile *wavFile);
int writeWavHeaderFile(WavFile *wavFile);
int writeWavDataFile(WavFile *wavFile);
int writeWavNormalizedDataFile(WavFile *wavFile);
int writeDescriptor(WavFile *wavFile, FILE *descriptorBase, FILE *log);
void closeWavFile(WavFile *wavFile);

#endif /*WAVE_FILE_H*/