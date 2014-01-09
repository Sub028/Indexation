//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: ERDELYI Jean-François
// Date de création: 01/12/13
//======================================================================//
// Fichier C: dynamiqueIntegerTab.c ou Fichier H: dynamiqueIntegerTab.h
//======================================================================//
// Module UTILITY (ALL):
// - Permet de créer et manipuler un tableau dynamique d'entier,
//   la valeur est incrémenté de un a chaque fois que l'on rentre la clé
//   on peut créer un tableau avec le nombres de valeurs connue ou non.
//======================================================================//

/**
 * \file dynamicIntegerTab.c
 * \author Jean-François Erdelyi
 * \brief Manipuler des tableau d'entier dynamique.
 * \version 1
 * \date 01 decembre 2013.
 * 
 * Permet de créer et manipuler un tableau dynamique d'entier,
 * la valeur est incrémenté de un a chaque fois que l'on rentre la clé
 * on peut créer un tableau avec le nombres de valeurs connue ou non.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "histogramSound.h"

/**
 * \fn void initTab(HistogramSound *tab, int nbValues)
 * \brief Initialise du tableau.
 *
 * \param tab Le tableau.
 * \param nbValues Le nombre de valeurs (si inconnue = 0).
 */
void initTab(HistogramSound *tab, int nbValues) {
	int i;
	tab->begin = NULL;
	tab->end = NULL;
	for(i = 0; i < nbValues; i++) {
		changeValueAt(tab, i, 0);
	}
}

/**
 * \fn void addValue(HistogramSound *tab, int key)
 * \brief Ajoute un valeur par incrément.
 *
 * \param tab Le tableau.
 * \param key L'indice du tableau.
 */
void addValue(HistogramSound *tab, int key) {
	HistogramSoundCell *currentCell = getHistogramSoundCell(tab, key);
	if(currentCell == NULL) {
		changeValueAt(tab, key, 1);
	} else {
		currentCell->value++;
	}
}

/**
 * \fn void changeValueAt(HistogramSound *tab, int key, int value)
 * \brief Modifie la valeur a l'indice donner.
 *
 * \param tab Le tableau.
 * \param key L'indice du tableau.
 * \param value La valeur.
 */
void changeValueAt(HistogramSound *tab, int key, int value) {
	HistogramSoundCell *currentCell = getHistogramSoundCell(tab, key);
	if(currentCell != NULL) {
		currentCell->value = value;
	} else {
		currentCell = (HistogramSoundCell*)malloc(sizeof(HistogramSoundCell));
		currentCell->value = value;
		currentCell->key = key;
		currentCell->nextCell = NULL;
		if(isVoid(tab)) {
			tab->begin = currentCell;
			tab->end = tab->begin;
		} else {
			tab->end->nextCell = currentCell;
			tab->end = tab->end->nextCell;
		}
	}
}

/**
 * \fn int isVoid(HistogramSound *tab)
 * \brief Retourne si le tableau est vide.
 *
 * \param tab Le tableau.
 * \return L'indice.
 */
int isVoid(HistogramSound *tab) {
	return(tab->begin == NULL);
}

/**
 * \fn HistogramSoundCell* getHistogramSoundCell(HistogramSound *tab, int key)
 * \brief Retourne la cellule correspondant a la clef.
 *
 * \param tab Le tableau.
 * \param key L'indice du tableau.
 * \return Une cellule ou NULL.
 */
HistogramSoundCell* getHistogramSoundCell(HistogramSound *tab, int key) {
	HistogramSoundCell *currentCell = NULL;
	if(!isVoid(tab)) {
		currentCell = tab->begin;
		while(currentCell != NULL) {
			if(currentCell->key == key) {
				break;
			}
			currentCell = currentCell->nextCell;
		}
	}
	return(currentCell);
}

/**
 * \fn void writeTab(HistogramSound *tab, FILE *file)
 * \brief Ecrit le tableau dans un fichier.
 *
 * \param tab Le tableau.
 * \param file Le fichier.
 */
void writeTab(HistogramSound *tab, FILE *file) {
	HistogramSoundCell *currentCell;
	if(!isVoid(tab)) {
		currentCell = tab->begin;
		while(currentCell != NULL) {
			fprintf(file, "%d", currentCell->value);
			currentCell = currentCell->nextCell;
			if(currentCell != NULL) {
				fprintf(file, "\t");
			}
		}
	}
}

/**
 * \fn void freeIntegerTab(HistogramSound *tab)
 * \brief Libére les cellules.
 *
 * \param tab Le tableau.
 */
void freeIntegerTab(HistogramSound *tab) {
	HistogramSoundCell *currentCell = tab->begin;
	HistogramSoundCell *nextCell;
	while(currentCell != NULL) {
		nextCell = currentCell->nextCell;
		free(currentCell);
		currentCell = nextCell;
	}
}