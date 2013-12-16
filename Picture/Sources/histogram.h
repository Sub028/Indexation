//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: VEILLARD Aurélien
// Date de création: 30/11/13
//======================================================================//
// Fichier H: histogram.h
//======================================================================//
// Fonctions:
// - 
//======================================================================//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matrix.h"

//======================================================================//

#ifndef HISTOGRAM
#define HISTOGRAM
typedef struct {
	int nbValue;;
	int** matrixHisto;
} Histogram;
#endif /* HISTOGRAM */

//======================================================================//

int initHistogram(Histogram* hist, int nbValue, FILE* log);
int removeHistogram(Histogram* hist, FILE* log);
int writingHistogram(Histogram* hist, FILE* descriptorBase, int nbBitQuantification);

//======================================================================//