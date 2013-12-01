//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: ERDELYI Jean-François
// Date de création: 01/12/13
//======================================================================//
// Fichier C: wavHeader.c ou Fichier H: wavHeader.h
//======================================================================//
// Module AUDIO :
// - Permet de manipuler les entête des fichiers wav
//======================================================================//

/**
 * \file wavHeader.c
 * \author Jean-François Erdelyi
 * \brief Permet de manipuler les entête des fichiers wav
 * \version 1
 * \date 01 decembre 2013.
 */


#include <stdio.h>
#include <string.h>
#include "wavHeader.h"

/**
 * \fn void initWavHeader(WavHeader *wavHeader)
 * \brief Initialise l'entête.
 *
 * \param wavHeader L'entête.
 */
void initWavHeader(WavHeader *wavHeader) {
	memset(wavHeader, 0, sizeof(WavHeader));
}

/**
 * \fn void writeHeader(WavHeader *wavHeader, FILE *file)
 * \brief Ecrit l'entête dans un fichier text.
 *
 * \param wavHeader L'entête.
 * \param file Le fichier de sortie.
 */
void writeHeader(WavHeader *wavHeader, FILE *file) {
	//The "RIFF" chunk descriptor
	fprintf(file, "RIFF\t\t: %.4s\n", wavHeader->chunkId);
	fprintf(file, "Size\t\t: %d\n", wavHeader->chunkSize);
	fprintf(file, "Format\t\t: %.4s\n", wavHeader->format);

	//The "fmt" sub-chunk descriptor
	fprintf(file, "FMT\t\t: %.4s\n", wavHeader->subChunk1Id);
	fprintf(file, "FMT Chunk Size\t: %d\n", wavHeader->subChunk1Size);
	fprintf(file, "Format\t\t: %d\n", wavHeader->audioFormat);
	fprintf(file, "Channels\t: %d\n", wavHeader->numChannels);
	fprintf(file, "Sample Rate\t: %d\n", wavHeader->sampleRate);
	fprintf(file, "Byte Rate\t: %d\n", wavHeader->byteRate);
	fprintf(file, "Block Align\t: %d\n", wavHeader->blockAlign);
	fprintf(file, "Bits Per Sample\t: %d\n", wavHeader->bitsPerSample);

	//The "data" sub-chunk descriptor
	fprintf(file, "Data\t\t: %.4s\n", wavHeader->subChunk2Id);
	fprintf(file, "Data Chunk Size\t: %d\n", wavHeader->subChunk2Size);
}

/**
 * \fn int writeWavHeader(WavHeader *wavHeader, FILE *file)
 * \brief Ecrit l'entête dans un fichier binaire wav.
 *
 * \param wavHeader L'entête.
 * \param file Le fichier de sortie.
 * \return La valeur du fwrite
 */
int writeWavHeader(WavHeader *wavHeader, FILE *file) {
	return(fwrite(wavHeader, sizeof(WavHeader), 1, file));
}

/**
 * \fn int readHeader(WavHeader *wavHeader, FILE *file)
 * \brief Permet de stocker l'entête d'un fichier wav en mémoire
 *
 * \param wavHeader L'entête.
 * \param file Le fichier de sortie.
 */
int readHeader(WavHeader *wavHeader, FILE *file) {
	return(fread(wavHeader, sizeof(WavHeader), 1, file));
}
