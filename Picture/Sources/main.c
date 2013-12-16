//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: VEILLARD Aurélien
// Date de création: 18/11/13
//======================================================================//
// Fichier C: main.c
//======================================================================//
// Fonctions:
// - 
//======================================================================//

/**
 * \file main.c
 * \author Aurélien Veillard
 * \brief Permet de tester le module Image.
 * \version 1.0
 * \date 18 Novembre 2013.
 */

//======================================================================//

#include "openPicture.h"
#include <time.h>

//======================================================================//

/**
 * \fn int main(int argc, char *argv[])
 * \brief Test la partie Image
 *
 * \param argc Nombre d'arguments passés
 * \param argv Attendu: le chemin d'accès du fichier à traiter
 * \return EXIT_SUCCESS ou EXIT_FAILURE
 */

int main(int argc, char* argv[]) {	
	FILE* picture = NULL;
	FILE* config = NULL;
	FILE* descriptorBase = NULL;
	FILE* log = NULL;
	time_t clock;
	
	int error, debug = 1;
	
	if(argc < 2) {
		fprintf(stderr, "\033[31m");
		fprintf(stderr, "> Bad utilisation: need filename\n");
		fprintf(stderr, "\033[00m");
		return EXIT_FAILURE; 
	}
	picture = fopen(argv[1], "r");	// Donc pour exécuter ./execute Data/xx.txt
	descriptorBase = fopen("Bases/liste_base_image.base", "a+");
	if(descriptorBase == NULL) {
		system("mkdir Bases");
		descriptorBase = fopen("Bases/liste_base_image.base", "a+");
	}
	if(debug) {
		log = fopen("log.log", "a");
		time(&clock);
		fprintf(log, "#%s", ctime(&clock));
	}
	if(picture != NULL) {
		fprintf(log, "> Openning success: %s\n", argv[1]);
		fflush(stdout);
		error = openPict(picture, log, descriptorBase, argv[1]);
	} else if(picture == NULL){
		fprintf(log, "> ERROR: can't open picture\n");
		fflush(stdout);
	} else {
		fprintf(log, "> ERROR: can't open configuration file\n");
		fflush(stdout);
	}
	
	fclose(picture);
	
	fprintf(log, "> Indexation of '%s' done!\n", argv[1]);
	
// 	if(error == 0) {
// 		fprintf(log, "> Indexation of '%s' done!\n", argv[1]);
// 	} else {
// 		fprintf(log, "> ERROR: indexation failed\n");
// 		return(EXIT_FAILURE);
// 	}
	
	if(debug) {
		fprintf(log, "> Closing: %s\n", argv[1]);
		fclose(log);
	}
	
	return(EXIT_SUCCESS);
}

//======================================================================//