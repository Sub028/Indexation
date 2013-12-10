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
 * \struct DynamicIntegerTab
 * \brief Tableau d'entier dynamique
 *
 * Pointe vers le debut et la fin du tableau
 */
typedef struct DynamicIntegerTab {
	IntegerTabCell *begin;
	IntegerTabCell *end;
} DynamicIntegerTab;

void initTab(DynamicIntegerTab *tab, int nbValues);
void changeValueAt(DynamicIntegerTab *tab, int key, int value);
int isVoid(DynamicIntegerTab *tab);
void addValue(DynamicIntegerTab *tab, int key);
IntegerTabCell* getIntegerTabCell(DynamicIntegerTab *tab, int key);
void writeTab(DynamicIntegerTab *tab, FILE *file);
void freeIntegerTab(DynamicIntegerTab *tab);

#endif /*DYNAMIQUE_INTEGRE_TAB_H*/