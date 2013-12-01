/**
 * \file wavHeader.h
 * \author Jean-François Erdelyi
 * \brief Permet de manipuler les entête des fichiers wav
 * \version 1
 * \date 01 decembre 2013.
 */


#ifndef WAV_HEADER_H
#define WAV_HEADER_H

/**
 * \struct WavHeader
 * \brief Contient les champ d'une entête d'un fichier wav.
 * \see https://ccrma.stanford.edu/courses/422/projects/WaveFormat/
 *
 * Permet de stocker l'entête d'un fichier wav
 */
typedef struct WavHeader {
	//The "RIFF" chunk descriptor
	char chunkId[4];
	int chunkSize;
	char format[4];

	//The "fmt" sub-chunk descriptor
	char subChunk1Id[4];
	int subChunk1Size;
	short audioFormat;
	short numChannels;
	int sampleRate;
	int byteRate;
	short blockAlign;
	short bitsPerSample;

	//The "data" sub-chunk descriptor
	char subChunk2Id[4];
	int subChunk2Size;
} WavHeader;

void initWavHeader(WavHeader *wavHeader);
void writeHeader(WavHeader *wavHeader, FILE *file);
int writeWavHeader(WavHeader *wavHeader, FILE *file);
int readHeader(WavHeader *wavHeader, FILE *file);

#endif /*WAV_HEADER_H*/