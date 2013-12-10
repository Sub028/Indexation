#ifndef DYNAMIC_CHAR_TAB_H
#define DYNAMIC_CHAR_TAB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

//structure d'une cellule
typedef struct Cel {
	char* key[MAX_BUFFER_SIZE];
	int value;
	struct Cel* ptr_next_cel;
} Cel;

//pointeurs de debut et fin sur l'histogramme
typedef struct Position {
	Cel* begin;
	Cel* end;
} Position;

//un histogramme est un pointeur sur une cellule
typedef Position* Histogram; 

//structure d'un descripteur
typedef struct Descriptor {
	int id;
	Histogram h;
	int nb_words;
} Descriptor;

void get_words(FILE *file);
//void addValue(String key, Histogram h);
void free_descriptor(Histogram h);

#endif /*DYNAMIC_CHAR_TAB_H*/
