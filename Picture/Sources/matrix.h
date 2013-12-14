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
// - Lecture du contenu des fichiers images (au format .txt)
// - Stockage des matrices des trois composantes par alloc dynamique
// - Libération de la mémoire allouée
//======================================================================//

#include <stdio.h>
#include <stdlib.h>
// #include "picture.h"

//======================================================================//

int** allocMatrix2D(int y, int x, FILE* log);
int freeMatrix2D(int** matrix2D, int x, FILE* log);

//======================================================================//