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
// 	- Création d'un histogramme
//	- Destruction d'un histogramme
//	- Ecriture d'un histogramme
//======================================================================//

/**
 * \file histogram.c
 * \author Aurélien Veillard
 * \brief Création d'un histogramme.
 * \version 1.0
 * \date 30 Novembre 2013
 * 
 * Permet la création d'un histogramme répresentatif de l'image traitée via une structure de données.
 */

//======================================================================//

#include "histogram.h"

//======================================================================//

/**
 * \fn int initHistogram(Histogram* hist, int nbValue, FILE* log)
 * \brief Initialisation d'un histogramme générique (pour RGB et BW).
 * \param hist Histogramme à initialiser.
 * \param nbValue Le nombre de valeur de l'histogramme, détermine la taille du tableau.
 * \param log Fichier de log.
 */

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

/**
 * \fn int removeHistogram(Histogram* hist, FILE* log)
 * \brief Suppression d'un histogramme générique (pour RGB et BW).
 * \param hist Histogramme à supprimer.
 * \param log Fichier de log.
 */

int removeHistogram(Histogram* hist, FILE* log) {
	freeMatrix2D(hist->matrixHisto, 2, log);	// 2 pour 2 colonnes
	hist->nbValue = -1;
}

//======================================================================//

/**
 * \fn int writingHistogram(Histogram* hist, FILE* descriptorBase, int nbBitQuantification)
 * \brief Ecriture de l'histogramme, ajout des occurences dans le tableau.
 * \param hist Histogramme à supprimer.
 * \param descriptorBase Fichier dans lequel seront écrit l'ensemble des descripteurs (donc les histogrammes).
 * \param nbBitQuantification Nombre de bit de quantification total (sur l'ensemble des composantes).
 */

int writingHistogram(Histogram* hist, FILE* descriptorBase, int nbBitQuantification) {
	int i;
	
	for(i = 0; i < pow(2, nbBitQuantification); i++) {	// Parcours de l'histogramme (tableau) en ligne
		fprintf(descriptorBase, "%d\t%d\n", hist->matrixHisto[0][i], hist->matrixHisto[1][i]);
		fflush(stdout);
	}
}

//======================================================================//