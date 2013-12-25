//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: ZERBIB Yoanna
// Date de création: 18/11/13
//======================================================================//
// Fichier C: parser.c
//======================================================================//
// Module TEXTES:
// - Indexation des textes (.xml)
//======================================================================//

#ifndef PARSER_H
#define PARSER_H

#include "histogram.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void get_words(FILE *file);
int good_word(char* word);
void replace_bad_letters(char c);

#endif /*PARSER_H*/
