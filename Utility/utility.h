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

void extractName(char fullName[100], char *nameOnly);
void createPath(char fullName[100], char prefix[100], char suffix[100], char *fileName);

#endif /*UTILITY_H*/