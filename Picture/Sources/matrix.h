//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: VEILLARD Aurélien
// Date de création: 18/11/13
//======================================================================//
// Fichier H: matrix.h
//======================================================================//
// Fonctions:
// 	- Création d'une matrice dynamique
// 	- Libération de la mémoire allouée à la matrice
//======================================================================//

#include <stdio.h>
#include <stdlib.h>

//======================================================================//

int** allocMatrix2D(int y, int x, FILE* log);
int freeMatrix2D(int** matrix2D, int x, FILE* log);

//======================================================================//