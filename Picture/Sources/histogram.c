//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: VEILLARD Aurélien
// Date de création: 30/11/13
//======================================================================//
// Fichier C: histogram.c
//======================================================================//
// Fonctions:
// - 
//======================================================================//

#include "histogram.h"

//======================================================================//

int initHistogram(Histogram* hist, int nbValue, FILE* log) {
	int i, valPixel = 0;
	
	hist->nbValue = nbValue;
	hist->matrixHisto = allocMatrix2D(2, hist->nbValue, log);	// 2 colonnes (colonne 0: valeurs, colonne 1: nb occurrence)
	for(i = 0; i < hist->nbValue; i++) {
		hist->matrixHisto[0][i] = valPixel;
		hist->matrixHisto[1][i] = 0;
		valPixel++;
	}
}

//======================================================================//

int removeHistogram(Histogram* hist, FILE* log) {
	freeMatrix2D(hist->matrixHisto, 2, log);	// 2 colonnes
	hist->nbValue = -1;
}

//======================================================================//

int writingHistogram(Histogram* hist, FILE* descriptorBase, int nbBitQuantification) {
	int i;
	
	for(i = 0; i < pow(2, nbBitQuantification); i++) {
		fprintf(descriptorBase, "%d\t%d\n", hist->matrixHisto[0][i], hist->matrixHisto[1][i]);
		fflush(stdout);
	}
}

//======================================================================//