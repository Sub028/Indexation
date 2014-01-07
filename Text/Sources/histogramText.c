//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: ZERBIB Yoanna
// Date de création: 18/11/13
//======================================================================//
// Fichier C: histogram.c
//======================================================================//
// Module TEXTES:
// - Indexation des textes (.xml)
//======================================================================//

#include "histogramText.h"
#include <time.h>

//fonction pour initialiser l'histogramme
void init_histogram(Histogram *h) {
	h->begin = NULL;
	h->end = NULL;
}

//fonction booleenne pour savoir si l'histogramme est vide
int is_void(Histogram *h) {
	return(h->begin == NULL);
}

//fonction qui retourne le nombre de mots d'un histogramme
int get_nb_words(Histogram *h) {
	Cel *current_cel = h->begin;
	int nb_words = 0;
	while (current_cel != NULL) {	
		nb_words++;
		current_cel = current_cel->ptr_next_cel;
	}
	return nb_words;
}

//fonction qui ecrit dans un fichier l'histogramme
void display_histogram(Histogram *h, FILE *out) {
	Cel *current_cel = h->begin;
	while(current_cel != NULL) {		
		fprintf(out, "%d\t%s\n", current_cel->value, current_cel->key);
		current_cel = current_cel->ptr_next_cel;
	}
}

//fonction a effectuer a la fin du programme appelant qui libere l'espace memoire du descripteur
void free_histogram(Histogram *h) {
	Cel *current_cel = h->begin;
	Cel *next_cel;
	while (current_cel != NULL) {
		next_cel = current_cel->ptr_next_cel;
		free(current_cel);
		current_cel = next_cel;				
	}
}
