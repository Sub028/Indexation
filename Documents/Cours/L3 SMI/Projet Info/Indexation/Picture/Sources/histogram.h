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
// 	- Création d'un histogramme
//	- Destruction d'un histogramme
//	- Ecriture d'un histogramme
//======================================================================//

/**
 * \file histogram.h
 * \author Aurélien Veillard
 * \brief Création d'un histogramme.
 * \version 1.0
 * \date 30 Novembre 2013
 * 
 * Permet la création d'un histogramme répresentatif de l'image traitée via une structure de données.
 */

//======================================================================//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matrix.h"

//======================================================================//

/**
 * \struct Histogram
 * \brief Structure représentative d'un histogramme générique.
 * 
 * Permet de stocker l'histogramme de l'image traitée (RGB ou BW) et le nombre de valeur de l'histogramme.
 */

#ifndef HISTOGRAM
#define HISTOGRAM
typedef struct {
	int nbValue;
	int** matrixHisto;
} Histogram;
#endif /* HISTOGRAM */

//======================================================================//

int initHistogram(Histogram* hist, int nbValue, FILE* log);
int removeHistogram(Histogram* hist, FILE* log);
int writingHistogram(Histogram* hist, FILE* descriptorBase, int nbBitQuantification);

//======================================================================//