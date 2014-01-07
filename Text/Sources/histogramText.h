//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: ZERBIB Yoanna
// Date de création: 18/11/13
//======================================================================//
// Fichier H: histogram.h
//======================================================================//
// Module TEXTES:
// - Indexation des textes (.xml)
//======================================================================//

#ifndef HISTOGRAM_TEXT_H
#define HISTOGRAM_TEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

//structure d'une cellule
typedef struct Cel {
	char key[MAX_BUFFER_SIZE];
	int value;
	struct Cel* ptr_next_cel;
} Cel;

//pointeurs de debut et fin sur l'histogramme
typedef struct Histogram {
	Cel* begin;
	Cel* end;
} Histogram;


//Sous-programmes des histogrammes
void init_histogram(Histogram *h);
int is_void(Histogram *h);
void display_histogram(Histogram *h, FILE *out);
int get_nb_words(Histogram *h);
void free_histogram(Histogram *h);

#endif /*HISTOGRAM_TEXT_H*/
