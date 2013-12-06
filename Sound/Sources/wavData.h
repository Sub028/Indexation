/**
 * \file wavData.h
 * \author Jean-François Erdelyi
 * \brief Permet de manipuler les données d'un fichier wav.
 * \version 1
 * \date 01 decembre 2013.
 */


#ifndef WAVE_DATA_H
#define WAVE_DATA_H

/**
 * \struct CelWavData
 * \brief Cellule de donnée audio.
 *
 * Permet de stocker une sample, et la cellule suivante
 */
typedef struct CelWavData {
	short sample;
	struct CelWavData *nextCell;
} CelWavData;

/**
 * \struct WavData
 * \brief Données d'un fichier
 *
 * Permet de connaitre la premiere et la derniere donnée d'un fichier charger
 * ainsi que le nombre de cellules.
 */
typedef struct WavData {
	int size;
	CelWavData *begin;
	CelWavData *end;
} WavData;

void initWavData(WavData *wavData);
void readWavData(WavData *wavData, FILE *file);
void writeWavData(WavData *wavData, FILE *file);
void writeData(WavData *wavData, FILE *file);
void writeNormalizedData(WavData *wavData, FILE *file);
void freeDataWav(WavData *wavData);

#endif /*WAVE_DATA_H*/