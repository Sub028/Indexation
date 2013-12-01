#ifndef WAVE_DATA_H
#define WAVE_DATA_H

typedef struct CelWavData {
	short sample;
	FILE *file;
	struct CelWavData *nextCell;
} CelWavData;

typedef struct WavData {
	int size;
	CelWavData *begin;
	CelWavData *end;
} WavData;

void initWavData(WavData *wavData);
void readWavData(WavData *wavData, FILE *file);
void writeWavData(WavData *wavData, FILE *file);
void freeDataWav(WavData *wavData);
void writeData(WavData *wavData, FILE *file);

#endif /*WAVE_DATA_H*/