//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: VEILLARD Aurélien
// Date de création: 30/11/13
//======================================================================//
// Fichier C: matrix.c
//======================================================================//
// Fonctions:
// 	- Création d'une matrice dynamique
// 	- Libération de la mémoire allouée à la matrice
//======================================================================//
// REPRESENTATION MATRICE 2D:
//
//	  | [] [] [] [] [] [] [] [] [] []
//	  | [] [] [] [] [] [] [] [] [] []
//	  | [] [] [] [] [] [] [] [] [] []
// 	  | [] [] [] [] [] [] [] [] [] []
//  sizeY | [] [] [] [] [] [] [] [] [] []
// nbLigne| [] [] [] [] [] [] [] [] [] []
//	  | [] [] [] [] [] [] [] [] [] []
//	  | [] [] [] [] [] [] [] [] [] []
//	  | [] [] [] [] [] [] [] [] [] []
//	  | [] [] [] [] [] [] [] [] [] []
//	    _____________________________
//		  sizeX = nbColonne
//
//======================================================================//

#include "matrix.h"

//======================================================================//
// Allocation dynamique de matrice x*y

int** allocMatrix2D(int y, int x, FILE* log) {
	int i = 0;
	int** matrix = NULL;	// Initialisation d'une matrice dynamique
	matrix = (int**)malloc(y*sizeof(int*));	// Malloc de la matrice (1er tableau)
	
	// Parcours du premier tableau (le tableau de pointeurs vers les tableaux qui formeront la matrice)
	for(i = 0; i < y; i++) {
		// Malloc des tableaux de la matrice
		matrix[i] = (int*)malloc(x*sizeof(int));
	}
	
	// Test pour savoir si la matrice a bien été crée
	if(matrix == NULL) {
		fprintf(log, "> ERROR: Matrix creation failed\n");
		fflush(stdout);
	}
	return matrix;
}

//======================================================================//

int freeMatrix2D(int** matrix2D, int y, FILE* log) {
	int i;
	
	// Parcours du tableau de pointeurs vers les tableaux
	for(i = 0; i < y; i++) {
		// Free des tableaux de la matrice
		free(matrix2D[i]);
	}
	
	// Free du tableau à l'origine de la matrice
	free(matrix2D);
}
//======================================================================//