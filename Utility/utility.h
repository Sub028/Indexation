/**
 * \file utility.h
 * \author Jean-François Erdelyi
 * \brief Permet de faire diverse manipulation utile pour le projets.
 * \version 1
 * \date 01 decembre 2013.
 * 
 * Permet de faire diverse manipulation utile pour le projets.
 * 
 */

#ifndef UTILITY_H
#define UTILITY_H

#define BUFFER_SIZE 100

int indexOfNameBegin(char *fullName);
void getStringUntil(char *input, char *output, char c);
void splitHeaderJustSize(char *header, int *nbBars, int *nbWindows);
void splitHeader(char *header, char *id, int *nbBars, int *nbWindows, char *date);
void splitDate(char *dateIn, char *dateOut);
int supprDescriptor(char *id, char *baseType);
int supprDescriptorHeader(FILE *base, char *line, char *baseType);
void extractName(char *fullName, char *nameOnly);
void extractExtension(char *fullName, char *extension);
void createPath(char *fullName, char *prefix, char *suffix, char *fileName);
int getIdInDescriptorBase(FILE *base, char *id, char *fileName);
void getDescriptor(FILE *base, char *id);
int getValueOf(char *key, int *value);
void checkDescriptorBase(FILE *base, FILE *log, char *baseType);
int getIfFileHasModified(char *id, char *fileName, FILE *log, char *baseType);

#endif /*UTILITY_H*/