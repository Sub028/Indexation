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

#include "histogram.h"
#include <time.h>

//fonction pour initialiser l'histogramme
void init_histogram(Histogram *h) {
	h->begin = NULL;
	h->end = NULL;
}

//fonction pour ajouter une nouvelle valeur dans l'histogramme
void add_value(char *key, Histogram *h) {
	Cel *current_cel;
	Cel *newc;
	
	//l'histogramme est vide
	if(is_void(h)) {
		newc = (Cel*)malloc(sizeof(Cel));
		strcpy(newc->key, key);
		newc->value = 1;
		newc->ptr_next_cel = NULL;
		h->begin = newc;
		h->end = newc;
	} else {
		current_cel = h->begin;
		while (current_cel != NULL) {	
			// le mot existe deja : on augmente juste son occurence
			if (strcmp(current_cel->key, key) == 0) {
				current_cel->value++;
				break;
			} else {
				// on passe a la cellule suivante
				current_cel = current_cel->ptr_next_cel;
			}
		}
		//le mot n'existe pas
		if (current_cel == NULL)  {
			newc = (Cel*)malloc(sizeof(Cel));
			strcpy(newc->key, key);
			newc->value = 1;
			newc->ptr_next_cel = NULL;		
			h->end->ptr_next_cel = newc;
			h->end = h->end->ptr_next_cel;
		}
	}
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
		fprintf(out, "%d - %s\n", current_cel->value, current_cel->key);
		current_cel = current_cel->ptr_next_cel;
	}
}

//fonction qui ecrit dans un fichier le descripteur
void display_descriptor(Histogram *h, FILE *out) {
	fprintf(out, "Id : ID%d\n", rand());
// 	fprintf(out, "Id : ID%d%s\n", rand(), extract_name());
	fprintf(out, "Occurence\tMot\n\n"); 
	display_histogram(h, out);
//	fprintf(out, "\nNombre de mots : %d\n", get_nb_words(h));	
}

//fonction qui sert a ajouter une ligne du descripeteur d'un texte dans le fichier liste_base_descripteurs
void add_list_base_descriptors() {
	FILE *out = fopen("Resultats/Liste_base_descripteurs.out", "w");
	fprintf(out, "Liste des descripteurs ayant ete faits :\n");
	fclose(out);
}

//fonction a effectuer a la fin du pg appelant qui libere l'espace memoire du descripteur
void free_descriptor(Histogram *h) {
	Cel *current_cel = h->begin;
	Cel *next_cel = current_cel->ptr_next_cel;
	if (current_cel != NULL) {
		free(current_cel);
		current_cel = next_cel;
		next_cel = current_cel->ptr_next_cel;		
	}
}
