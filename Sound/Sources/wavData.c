//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: ERDELYI Jean-François
// Date de création: 01/12/13
//======================================================================//
// Fichier C: wavData.c ou Fichier H: wavData.h
//======================================================================//
// Module AUDIO :
// - Permet de manipuler les données d'un fichier wav
//======================================================================//

/**
 * \file wavData.c
 * \author Jean-François Erdelyi
 * \brief Permet de manipuler les données d'un fichier wav.
 * \version 1
 * \date 01 decembre 2013.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wavData.h"

/**
 * \fn void initWavData(WavData *wavData)
 * \brief Initialise les données.
 *
 * \param wavData Les données.
 */
void initWavData(WavData *wavData) {
        wavData->begin = NULL;
        wavData->end = NULL;
        wavData->size = 0;
}

/**
 * \fn void readWavData(WavData *wavData, FILE *file)
 * \brief Permet de lire les données et de les stocker en mémoire.
 *
 * \param wavData Les données.
 * \param file Un fichier wav en entrée.
 */
void readWavData(WavData *wavData, FILE *file) {
        short currentValue;
        CelWavData *currentCel;
        while(fread(&currentValue, sizeof(short), 1, file)) {
                currentCel = (CelWavData*)malloc(sizeof(CelWavData));
                currentCel->sample = currentValue;
                currentCel->nextCell = NULL;
                if(wavData->begin == NULL) {
                        wavData->begin = currentCel;
                        wavData->end = currentCel;
                } else {
                        wavData->end->nextCell = currentCel;
                        wavData->end = wavData->end->nextCell;
                }
                wavData->size++;
        }
}

/**
 * \fn void writeWavData(WavData *wavData, FILE *file)
 * \brief Permet d'ecrire les données en binaire sur un fichier.
 *
 * \param wavData Les données.
 * \param file Un fichier wav de sortie.
 */
void writeWavData(WavData *wavData, FILE *file) {
        CelWavData *currentCel = wavData->begin;
        while(currentCel != NULL) {
                fwrite(&currentCel->sample, sizeof(currentCel->sample), 1, file);
                currentCel = currentCel->nextCell;
        }
}

/**
 * \fn void freeDataWav(WavData *wavData)
 * \brief Libere les cellules
 *
 * \param wavData Les données.
 */
void freeDataWav(WavData *wavData) {
        CelWavData *currentCel = wavData->begin;
        CelWavData *nextCell;
        while(currentCel != NULL) {
                nextCell = currentCel->nextCell;
                free(currentCel);
                currentCel = nextCell;
        }
}

/**
 * \fn void writeData(WavData *wavData, FILE *file)
 * \brief Permet d'ecrire les données dans un fichier texte.
 *
 * \param wavData Les données.
 * \param file Un fichier txt de sortie.
 */
void writeData(WavData *wavData, FILE *file) {
        CelWavData *currentCel = wavData->begin;
        while(currentCel != NULL) {
                fprintf(file, "%d\n", currentCel->sample);
                currentCel = currentCel->nextCell;
        }
}

/**
 * \fn void writeData(WavData *wavData, FILE *file)
 * \brief Permet d'ecrire les données normalisée dans un fichier texte.
 *
 * \param wavData Les données.
 * \param file Un fichier txt de sortie.
 */
void writeNormalizedData(WavData *wavData, FILE *file) {
        CelWavData *currentCel = wavData->begin;
        while(currentCel != NULL) {
                fprintf(file, "%e\n", currentCel->sample / pow(2, 15));
                currentCel = currentCel->nextCell;
        }
}