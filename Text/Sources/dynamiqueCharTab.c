#include "dynamicCharTab.h"

void addValue(String key, Histogram *h) {
	Cel *currentCell = h->ptr_next_cel;

	while (currentCell != NULL) {	
		// le mot existe deja : on augmente juste son occurence
		if (strcmp(currentCell->key, key)) {
			currentCell->value++;
			break;
		} else {
			// on passe a la cel suivante
			currentCell = currentCell->ptr_next_cel;
			if (currentCell->ptr_next_cel == NULL)  {
				//le mot n'existe pas
				newc = (cel*)malloc(sizeof(Cel));
				newc->key = key;
				new->value = 1;				
				newc->end->ptr_next_cel = NULL;
			}
		}
	}
}*/

//fct a effectuer a la fin du pg appelant (sinon stack overflow !)  A REVOOOOOOIR 
void free_descriptor(Histogram h) {
	h = NULL;
}

int get_nb_Words(Histogram h) {
	int nbWords = 0;
	while (h.ptr_next_cel != NULL) {	
		nbWords++;
		h = h.ptr_next_cel;
	}
	return nbWords;
}

void display_histo(Histogram h) {
	
}

void display_descriptor(Histogram h) {
	printf("\n1\n"); // EN VRAI CA SERA L'ID !!!!!!!!!!!
	display_histo(h);
	printf("\n%d\n", get_nb_Words(h));
}