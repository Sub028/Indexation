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

/**
 * \file matrix.c
 * \author Aurélien Veillard
 * \brief Permet de créer des matrices dynamiques.
 * \version 1.0
 * \date 30 Novembre 2013
 */

//======================================================================//

#include "matrix.h"

//======================================================================//

/**
 * \fn int** allocMatrix2D(int y, int x, FILE* log)
 * \brief Allocation d'une matrice dynamique.
 * \param y Taille y de l'image (en hauteur).
 * \param x Taille x de l'image (en largeur).
 * \param log Fichier de log.
 * \return matrix : la matrice dynamique récemment créée.
 */

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
		fprintf(log, "ERROR: Matrix creation failed\n");
		fflush(stdout);
	}
	return matrix;
}

//======================================================================//

/**
 * \fn int freeMatrix2D(int** matrix2D, int y, FILE* log)
 * \brief Suppression d'une matrice dynamique.
 * \param matrix2D Matrice dynamique à supprimer.
 * \param y Taille y de l'image (en hauteur).
 * \param log Fichier de log.
 */

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