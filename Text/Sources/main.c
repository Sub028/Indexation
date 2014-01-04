//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: ZERBIB Yoanna
// Date de création: 18/11/13
//======================================================================//
// Fichier C: main.c
//======================================================================//
// Module TEXTES:
// - Indexation des textes (.xml)
//======================================================================//

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "histogramText.h"
#include "descriptor.h"
#include "time.h"

int main(int argc, char *argv[]) {
	time_t clock;
	
	FILE *log = fopen("log.log", "a+");
	time(&clock);
	fprintf(log, "#%s\n", ctime(&clock));
	system("mkdir Bases");
	FILE *textBase = fopen("Bases/base_descripteur_text.base", "a");

	//les cas d'erreur
	if (argc < 2) {
		fprintf(stderr, "Need filename\n");
		return EXIT_FAILURE;
	}		
	FILE *fic = fopen(argv[1], "r");
	if (fic != NULL) {
		fprintf(log, "Opening success : %s\n", argv[1]);
	}
	else if (fic == NULL) {
		fprintf(log, "ERROR : Can't open this text'\n");
		fflush(stdout);
		return (EXIT_FAILURE);		
	}
	else {
		fprintf(log, "ERROR : Can't open config file'\n");
		fflush(stdout);
	}
	
	//l'indexation
	get_words(fic, log, textBase, argv[1]);
	
	//on ferme le fichier
	fclose(fic);
	fprintf(log, "Indexation of %s DONE !\n", argv[1]);
	fprintf(log, "Closing %s\n\n", argv[1]);
	fclose(log);
	
	return(EXIT_SUCCESS);
}


