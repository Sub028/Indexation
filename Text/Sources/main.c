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
#include "histogram.h"

int main(int argc, char *argv[]) {	
	//les cas d'erreur
	if (argc < 2) {
		printf("Nom du fichier requis\n");
		return (EXIT_FAILURE);
	}		
	FILE *fic = fopen(argv[1], "r");
	
	if (fic == NULL) {
		printf("Erreur lors de l'ouverture du fichier\n");
		return (EXIT_FAILURE);
	}
	//l'indexation
	get_words(fic);
	
	//on ferme le fichier
	fclose(fic);
	return(EXIT_SUCCESS);
}


