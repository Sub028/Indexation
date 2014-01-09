//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: ERDELYI Jean-François
// Date de création: 01/12/13
//======================================================================//
// Fichier C: main.c
//======================================================================//
// Module AUDIO :
// - Permet de tester le module Audio "alone"
//======================================================================//

/**
 * \file main.c
 * \author Jean-François Erdelyi
 * \brief Permet de tester le module Audio "alone".
 * \version 1
 * \date 01 decembre 2013.
 */

#include <stdio.h>
#include <stdlib.h>
#include "wavFile.h"

/**
 * \fn int main(int argc, char *argv[])
 * \brief Test la partie Audio
 *
 * \param argc Rien.
 * \param argv Rien attendu...
 * \return EXIT_SUCCESS ou EXIT_FAILURE
 */
int main(int argc, char *argv[]) {
	FILE *desciptorBase;
	FILE *log;
	char currentId[BUFFER_SIZE] = {0};
	char *currentFileName = "Data/Jingle.wav";

	desciptorBase = fopen("Bases/liste_base_audio.base", "a+");
	if(desciptorBase == NULL) {
		system("mkdir Bases");
		desciptorBase = fopen("Bases/liste_base_audio.base", "a+");
	}
	if((log = fopen("log.log", "a")) == NULL) {
		perror("Impossible d'ouvrir le fichier ");
		return(EXIT_FAILURE);
	}
	WavFile wavFile;
	openWavFile(&wavFile, currentFileName);

// 	writeWavFile(&wavFile);
// 	writeWavHeaderFile(&wavFile);
// 	writeWavDataFile(&wavFile);
// 	writeWavNormalizedDataFile(&wavFile);

	getIdInDescriptorBase(desciptorBase, currentId, currentFileName);
	writeDescriptor(&wavFile, desciptorBase, log);
	
	printf("DONE ! %d \n", sizeof(WavHeader));
	closeWavFile(&wavFile);
	close(desciptorBase);
	return(EXIT_SUCCESS);
}