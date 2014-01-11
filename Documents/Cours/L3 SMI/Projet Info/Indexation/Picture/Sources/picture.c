//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: VEILLARD Aurélien
// Date de création: 11/12/13
//======================================================================//
// Fichier C: picture.c
//======================================================================//
// Fonctions:
//	- Initialisation de la structure image couleur et blanc/noir
//	- Destruction de la structure temporaire
//	- Stockage temporaire de l'image
//======================================================================//

/**
 * \file picture.c
 * \author Aurélien Veillard
 * \author Aurélien Veillard
 * \brief Permet d'initialiser une structure de type image.
 * \version 1.0
 * \date 18 Novembre 2013
 * 
 * La structure de type image contient 1 ou 3 matrice(s) représentative(s) de l'image traitée.
 */


//======================================================================//

#include "picture.h"

//======================================================================//

/**
 * \fn int initPictureRGB(PictureRGB* pictRGB, int y, int x, char* filename, FILE* log)
 * \brief Initialisation de la structure Picture RGB.
 * \param pictRGB Structure représentative de l'image traitée.
 * \param y Taille de l'image en y (hauteur).
 * \param x Taille de l'image en x (largeur).
 * \param filename Nom de l'image.
 * \param log Fichier de log.
 */

int initPictureRGB(PictureRGB* pictRGB, int y, int x, char* filename, FILE* log) {
	pictRGB->filename = (char*)malloc(sizeof(*filename));	// Allocation de l'espace necessaire pour le nom du fichier traité
	strcpy(pictRGB->filename, filename);	// Mémorisation du nom
	pictRGB->sizeY = y;	// Mémorisation de la hauteur
	pictRGB->sizeX = x;	// Mémorisation de la largeur
	pictRGB->component = 3;	// Mémorisation du nombre de composantes
	pictRGB->matrixRed = allocMatrix2D(pictRGB->sizeY, pictRGB->sizeX, log);	// Allocation de la matrice dédiée à la composante rouge
	pictRGB->matrixGreen = allocMatrix2D(pictRGB->sizeY, pictRGB->sizeX, log);	// Allocation de la matrice dédiée à la composante verte
	pictRGB->matrixBlue = allocMatrix2D(pictRGB->sizeY, pictRGB->sizeX, log);	// Allocation de la matrice dédiée à la composante bleue
}

//======================================================================//

/**
 * \fn int initPictureBW(PictureBW* pictBW, int y, int x, char* filename, FILE* log)
 * \brief Initialisation de la structure Picture BW contenant.
 * \param pictBW Structure représentative de l'image traitée.
 * \param y Taille de l'image en y (hauteur).
 * \param x Taille de l'image en x (largeur).
 * \param filename Nom de l'image.
 * \param log Fichier de log.
 */

int initPictureBW(PictureBW* pictBW, int y, int x, char* filename, FILE* log) {
	pictBW->filename = (char*)malloc(sizeof(*filename));	// Allocation de l'espace necessaire pour le nom du fichier traité
	strcpy(pictBW->filename, filename);	// Mémorisation du nom
	pictBW->sizeY = y;	// Mémorisation de la hauteur
	pictBW->sizeX = x;	// Mémorisation de la largeur
	pictBW->component = 1;	// Mémorisation du nombre de composantes
	pictBW->matrixGrey = allocMatrix2D(pictBW->sizeY, pictBW->sizeX, log);	// Allocation de la matrice dédiée à la composante grise
}

//======================================================================//

/**
 * \fn int removePictureRGB(PictureRGB* pictRGB, FILE* log)
 * \brief Suppression de la structure Picture RGB contenant la matrice RGB de l'image.
 * \param pictRGB Structure représentative de l'image traitée.
 * \param log Fichier de log.
 */

int removePictureRGB(PictureRGB* pictRGB, FILE* log) {
	freeMatrix2D(pictRGB->matrixRed, pictRGB->sizeY, log);		// Libération de la mémoire dédiée à la matrice rouge
	freeMatrix2D(pictRGB->matrixGreen, pictRGB->sizeY, log);	// Libération de la mémoire dédiée à la matrice verte
	freeMatrix2D(pictRGB->matrixBlue, pictRGB->sizeY, log);		// Libération de la mémoire dédiée à la matrice bleue
}

//======================================================================//

/**
 * \fn int removePictureBW(PictureBW* pictBW, FILE* log)
 * \brief Suppression de la structure Picture BW contenant la matrice BW de l'image.
 * \param pictBW Structure représentative de l'image traitée.
 * \param log Fichier de log.
 */

int removePictureBW(PictureBW* pictBW, FILE* log) {
	freeMatrix2D(pictBW->matrixGrey, pictBW->sizeY, log);	// Libération de la mémoire dédiée à la matrice grise
}

//======================================================================//

/**
 * \fn int storagePictureRGB(PictureRGB* pictRGB, FILE* picture)
 * \brief Stockage temporaire de l'image RGB.
 * \param pictRGB Structure représentative de l'image traitée.
 * \param log Fichier de log.
 * 
 * Lecture du fichier .txt correspondant à l'image traitée et stockage des valeurs lues dans la structure pictRGB correspondante.
 */

int storagePictureRGB(PictureRGB* pictRGB, FILE* picture) {
	// STOCKAGE TEMPORAIRE DES COMPOSANTES
	int i, j;
	
	// 1ere matrice: matrice rouge
	for(i = 0; i < pictRGB->sizeY; i++) {	// Parcours en ligne
		for(j = 0; j < pictRGB->sizeX; j++) {	// Parcours en colonne
			fscanf(picture, "%d", &pictRGB->matrixRed[i][j]);	// Mémorisation de la valeur
		}
	}
	
	// 2ième matrice: matrice verte
	for(i = 0; i < pictRGB->sizeY; i++) {	// Parcours en ligne
		for(j = 0; j < pictRGB->sizeX; j++) {	// Parcours en colonne
			fscanf(picture, "%d", &pictRGB->matrixGreen[i][j]);	// Mémorisation de la valeur
		}
	}
	
	// 3ième matrice: matrice bleue
	for(i = 0; i < pictRGB->sizeY; i++) {	// Parcours en ligne
		for(j = 0; j < pictRGB->sizeX; j++) {	// Parcours en colonne
			fscanf(picture, "%d", &pictRGB->matrixBlue[i][j]);	// Mémorisation de la valeur
		}
	}
}

//======================================================================//

/**
 * \fn int storagePictureBW(PictureBW* pictBW, FILE* picture)
 * \brief Stockage temporaire de l'image BW.
 * \param pictBW Structure représentative de l'image traitée.
 * \param log Fichier de log.
 * 
 * Lecture du fichier .txt correspondant à l'image traitée et stockage des valeurs lues dans la structure pictBW correspondante.
 */

int storagePictureBW(PictureBW* pictBW, FILE* picture) {
	// STOCKAGE TEMPORAIRE DE LA COMPOSANTE GRISE
	int i, j;
	
	// Matrice grey
	for(i = 0; i < pictBW->sizeY; i++) {	// Parcours en ligne
		for(j = 0; j < pictBW->sizeX; j++) {	// Parcours en colonne
			fscanf(picture, "%d", &pictBW->matrixGrey[i][j]);	// Mémorisation de la valeur
		}
	}
}

//======================================================================//