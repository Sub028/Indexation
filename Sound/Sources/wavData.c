#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wavData.h"

void initWavData(WavData *wavData) {
        wavData->begin = NULL;
        wavData->end = NULL;
        wavData->size = 0;
}

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

void writeWavData(WavData *wavData, FILE *file) {
        CelWavData *currentCel = wavData->begin;
        while(currentCel != NULL) {
                fwrite(&currentCel->sample, sizeof(currentCel->sample), 1, file);
                currentCel = currentCel->nextCell;
        }
}

void freeDataWav(WavData *wavData) {
        CelWavData *currentCel = wavData->begin;
        CelWavData *nextCell;
        while(currentCel != NULL) {
                nextCell = currentCel->nextCell;
                free(currentCel);
                currentCel = nextCell;
        }
}

void writeData(WavData *wavData, FILE *file) {
        CelWavData *currentCel = wavData->begin;
        while(currentCel != NULL) {
                fprintf(file, "%d\n", currentCel->sample);
                currentCel = currentCel->nextCell;
        }
}

void writeNormalizedData(WavData *wavData, FILE *file) {
        CelWavData *currentCel = wavData->begin;
        while(currentCel != NULL) {
                fprintf(file, "%e\n", currentCel->sample / pow(2, 15));
                currentCel = currentCel->nextCell;
        }
}