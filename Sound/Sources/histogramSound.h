/**
 * \file dynamiqueIntegerTab.h
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

#ifndef HISTOGRAM_SOUND_H
#define HISTOGRAM_SOUND_H

/**
 * \struct HistogramSoundCell
 * \brief Cellule d'un tableau dynamique.
 *
 * Permet de stocker une clef et sa valeur associer,
 * mais aussi la cellule suivante
 */
typedef struct HistogramSoundCell {
	int key;
	int value;
	struct HistogramSoundCell *nextCell;
} HistogramSoundCell;

/**
 * \struct HistogramSound
 * \brief Tableau d'entier dynamique
 *
 * Pointe vers le debut et la fin du tableau
 */
typedef struct HistogramSound {
	HistogramSoundCell *begin;
	HistogramSoundCell *end;
} HistogramSound;

void initTab(HistogramSound *tab, int nbValues);
void changeValueAt(HistogramSound *tab, int key, int value);
int isVoid(HistogramSound *tab);
void addValue(HistogramSound *tab, int key);
HistogramSoundCell* getHistogramSoundCell(HistogramSound *tab, int key);
void writeTab(HistogramSound *tab, FILE *file);
void freeIntegerTab(HistogramSound *tab);

#endif /*HISTOGRAM_SOUND_H*/