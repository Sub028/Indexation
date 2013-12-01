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

#ifndef DYNAMIQUE_INTEGRE_TAB_H
#define DYNAMIQUE_INTEGRE_TAB_H

/**
 * \struct IntegerTabCell
 * \brief Cellule d'un tableau dynamique.
 *
 * Permet de stocker une clef et sa valeur associer,
 * mais aussi la cellule suivante
 */
typedef struct IntegerTabCell {
	int key;
	int value;
	struct IntegerTabCell *nextCell;
} IntegerTabCell;

/**
 * \struct DynamiqueIntegerTab
 * \brief Tableau d'entier dynamique
 *
 * Pointe vers le debut et la fin du tableau
 */
typedef struct DynamiqueIntegerTab {
	IntegerTabCell *begin;
	IntegerTabCell *end;
} DynamiqueIntegerTab;

void initTab(DynamiqueIntegerTab *tab, int nbValues);
void changeValueAt(DynamiqueIntegerTab *tab, int key, int value);
void addValue(DynamiqueIntegerTab *tab, int key);
IntegerTabCell* getIntegerTabCell(DynamiqueIntegerTab *tab, int key);
void freeIntegerTab(DynamiqueIntegerTab *tab);

#endif /*DYNAMIQUE_INTEGRE_TAB_H*/