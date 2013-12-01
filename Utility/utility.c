//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: ERDELYI Jean-François
// Date de création: 01/12/13
//======================================================================//
// Fichier C: utility.c ou Fichier H: utility.h
//======================================================================//
// Module UTILITY (ALL):
// - Permet de faire diverse manipulation utile pour le projets.
//======================================================================//

/**
 * \file utility.c
 * \author Jean-François Erdelyi
 * \brief Permet de faire diverse manipulation utile pour le projets.
 * \version 1
 * \date 01 decembre 2013.
 * 
 * Permet de faire diverse manipulation utile pour le projets.
 * 
 */


#include <string.h>
#include "utility.h"

/**
 * \fn int indexOfNameBegin(char fullName[100])
 * \brief Retourne a partir d'ou le nom de fichier commence.
 *
 * \param fullName Le chemin complet du fichier.
 * \return L'indice d'ou le nom de fichier commence.
 */
int indexOfNameBegin(char fullName[100]) {
	int i;
	int index = 0;

	for(i = 0; i < 100, fullName[i] != '\0'; i++) {
		if(fullName[i] == '/') {
			index = i + 1;
		}
	}
	return(index);
}

/**
 * \fn void extractName(char fullName[100], char *nameOnly)
 * \brief Retourne la cellule correspondant a la clef.
 *
 * \param fullNameLe Le chemin complet du fichier.
 * \param nameOnly Le nom brut.
 */
void extractName(char fullName[100], char *nameOnly) {
	char name[100] = {0};
	int i, j;
	int begin = indexOfNameBegin(fullName);

	for(i = begin, j = 0; i < 100; i++, j++) {
		if(fullName[i] == '.') {
			break;
		}
		name[j] = fullName[i];
	}
	strcpy(nameOnly, name);
}

/**
 * \fn void createPath(char fullName[100], char prefix[100], char suffix[100], char *fileName)
 * \brief Crée un nouveau chemin pour un fichier
 *
 * \param fullName Le chemin complet du fichier.
 * \param prefix Ce qui va etre avant le nom du fichier.
 * \param suffix Ce qui va etre apres le nom du fichier.
 * \param fileName Le nouveau chemin.
 * 
 * Exemple : 
 * fullName = Data/Test.wav
 * prefix = Results/
 * suffix = _resultat.wav
 * le nouveau chemin sera :
 * fileName = Results/Test_resultat.wav
 */
void createPath(char fullName[100], char prefix[100], char suffix[100], char *fileName) {
	char buffer[100] = {0};
	char nameOnly[100];

	extractName(fullName, nameOnly);
	strcpy(buffer, prefix);
	strcat(buffer, nameOnly);
	strcat(buffer, suffix);
	strcpy(fileName, buffer);
}