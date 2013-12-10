#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "histogram.h"

void init_histogram(Histogram *h) {
	h->begin = NULL;
	h->end = NULL;
}

void addValue(char *key, Histogram *h) {
	Cel *currentCell;
	Cel *newc;

	//l'histogramme est vide
	if(isVoid(h)) {
		newc = (Cel*)malloc(sizeof(Cel));
		strcpy(newc->key, key);
		newc->value = 1;
		newc->ptr_next_cel = NULL;
		h->begin = newc;
		h->end = newc;
	} else {
		currentCell = h->begin;
		while (currentCell != NULL) {	
			// le mot existe deja : on augmente juste son occurence
			if (strcmp(currentCell->key, key) == 0) {
				currentCell->value++;
				break;
			} else {
				// on passe a la cel suivante
				currentCell = currentCell->ptr_next_cel;
			}
		}
		//le mot n'existe pas
		if (currentCell == NULL)  {
			newc = (Cel*)malloc(sizeof(Cel));
			strcpy(newc->key, key);
			newc->value = 1;
			newc->ptr_next_cel = NULL;		
			h->end->ptr_next_cel = newc;
			h->end = h->end->ptr_next_cel;
		}
	}
}

int isVoid(Histogram *h) {
	return(h->begin == NULL);
}

// int get_nb_Words(Histogram h) {
// 	int nbWords = 0;
// 	while (h.ptr_next_cel != NULL) {	
// 		nbWords++;
// 		h = h.ptr_next_cel;
// 	}
// 	return nbWords;
// }


void display_histo(Histogram *h, FILE *log) {
	Cel *currentCel = h->begin;
	while(currentCel != NULL) {
		fprintf(log, "%s\t%d\n", currentCel->key, currentCel->value);
		currentCel = currentCel->ptr_next_cel;
	}
}

// void display_descriptor(Histogram h) {
// 	printf("\n1\n"); // EN VRAI CA SERA L'ID !!!!!!!!!!!
// 	display_histo(h);
// 	printf("\n%d\n", get_nb_Words(h));
// }

//fct a effectuer a la fin du pg appelant
void free_descriptor(Histogram *h) {
	Cel *currentCel = h->begin;
	Cel *nextCel = currentCel->ptr_next_cel;
	if (currentCel != NULL) {
		free(currentCel);
		currentCel = nextCel;
		nextCel = currentCel->ptr_next_cel;		
	}
}