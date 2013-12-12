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

#ifndef HISTOGRAM_RGB
#define HISTOGRAM_RGB
typedef struct {
	int nbValue;
	int columnQuantRGB;
	int** matrixHistoRGB;
} HistogramRGB;
#endif /* HISTOGRAM_RGB */

//======================================================================//

#ifndef HISTOGRAM_BW
#define HISTOGRAM_BW
typedef struct {
	int nbValue;
	int columnQuantBW;
	int** matrixHistoBW;
} HistogramBW;
#endif /* HISTOGRAM_BW */

//======================================================================//

int initHistogram(Histogram* hist, int nbValue, FILE* log);
int removeHistogram(Histogram* hist, FILE* log);

//======================================================================//