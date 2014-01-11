//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: ZERBIB Yoanna
// Date de création: 18/11/13
//======================================================================//
// Fichier H: parser.h
//======================================================================//
// Module TEXTES:
// - Indexation des textes (.xml)
//======================================================================//

#include <stdio.h>
#include <stdlib.h>
#include "Utility/utility.h"

#ifndef PARSER_H
#define PARSER_H

int good_word(char* word, FILE *log);
int get_words(FILE *file, FILE *log, FILE *descriptorBase, char *filename);

#endif /*PARSER_H*/
