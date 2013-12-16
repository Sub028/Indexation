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
 * \brief Permet d'initialiser une structure de type image qui contient 1 ou 3 matrice(s)
 * 	représentative(s) de l'image traitée, suppression de l'image, stockage temporaire de l'image.
 * \version 1.0
 * \date 11 Décembre 2013
 */

//======================================================================//

#include "picture.h"

//======================================================================//

/**
 * \fn int initPictureRGB(PictureRGB* pictRGB, int y, int x, char* filename, FILE* log)
 * \brief Initialisation de la structure Picture RGB contenant les 3 matrices RGB de l'image, 
 * 	les tailles x et y, le nom de l'image et le nombre de composantes.
 * \param pictRGB Structure représentative de l'image traitée.
 * \param y Taille de l'image en y (hauteur).
 * \param x Taille de l'image en x (largeur).
 * \param filename Nom de l'image.
 * \param log Fichier de log.
 */

int initPictureRGB(PictureRGB* pictRGB, int y, int x, char* filename, FILE* log) {
	pictRGB->filename = (char*)malloc(sizeof(*filename));
	strcpy(pictRGB->filename, filename);
	pictRGB->sizeY = y;
	pictRGB->sizeX = x;
	pictRGB->component = 3;
	pictRGB->matrixRed = allocMatrix2D(pictRGB->sizeY, pictRGB->sizeX, log);
	pictRGB->matrixGreen = allocMatrix2D(pictRGB->sizeY, pictRGB->sizeX, log);
	pictRGB->matrixBlue = allocMatrix2D(pictRGB->sizeY, pictRGB->sizeX, log);
}

//======================================================================//

/**
 * \fn int initPictureBW(PictureBW* pictBW, int y, int x, char* filename, FILE* log)
 * \brief Initialisation de la structure Picture BW contenant la matrice BW de l'image, 
 * 	les tailles x et y, le nom de l'image et le nombre de composantes.
 * \param pictBW Structure représentative de l'image traitée.
 * \param y Taille de l'image en y (hauteur).
 * \param x Taille de l'image en x (largeur).
 * \param filename Nom de l'image.
 * \param log Fichier de log.
 */

int initPictureBW(PictureBW* pictBW, int y, int x, char* filename, FILE* log) {
	pictBW->filename = (char*)malloc(sizeof(*filename));
	strcpy(pictBW->filename, filename);
	pictBW->sizeY = y;
	pictBW->sizeX = x;
	pictBW->component = 1;
	pictBW->matrixGrey = allocMatrix2D(pictBW->sizeY, pictBW->sizeX, log);	
}

//======================================================================//

/**
 * \fn int removePictureRGB(PictureRGB* pictRGB, FILE* log)
 * \brief Suppression de la structure Picture RGB contenant la matrice RGB de l'image, 
 * 	les tailles x et y, le nom de l'image et le nombre de composantes.
 * \param pictRGB Structure représentative de l'image traitée.
 * \param log Fichier de log.
 */

int removePictureRGB(PictureRGB* pictRGB, FILE* log) {
	freeMatrix2D(pictRGB->matrixRed, pictRGB->sizeY, log);
	freeMatrix2D(pictRGB->matrixGreen, pictRGB->sizeY, log);
	freeMatrix2D(pictRGB->matrixBlue, pictRGB->sizeY, log);
}

//======================================================================//

/**
 * \fn int removePictureBW(PictureBW* pictBW, FILE* log)
 * \brief Suppression de la structure Picture BW contenant la matrice BW de l'image, 
 * 	les tailles x et y, le nom de l'image et le nombre de composantes.
 * \param pictBW Structure représentative de l'image traitée.
 * \param log Fichier de log.
 */

int removePictureBW(PictureBW* pictBW, FILE* log) {
	freeMatrix2D(pictBW->matrixGrey, pictBW->sizeY, log);
}

//======================================================================//

/**
 * \fn int storagePictureRGB(PictureRGB* pictRGB, FILE* picture)
 * \brief Lecture du fichier .txt correspondant à l'image traitée
 * 	et stockage des valeurs lues dans la structure pictRGB correspondante.
 * \param pictRGB Structure représentative de l'image traitée.
 * \param log Fichier de log.
 */

int storagePictureRGB(PictureRGB* pictRGB, FILE* picture) {
	// STOCKAGE TEMPORAIRE DES COMPOSANTES
	int i, j;
	
	// 1ere matrice: matrice rouge
	for(i = 0; i < pictRGB->sizeY; i++) {
		for(j = 0; j < pictRGB->sizeX; j++) {
			fscanf(picture, "%d", &pictRGB->matrixRed[i][j]);
		}
	}
	
	// 2ième matrice: matrice verte
	for(i = 0; i < pictRGB->sizeY; i++) {
		for(j = 0; j < pictRGB->sizeX; j++) {
			fscanf(picture, "%d", &pictRGB->matrixGreen[i][j]);
		}
	}
	
	// 3ième matrice: matrice bleue
	for(i = 0; i < pictRGB->sizeY; i++) {
		for(j = 0; j < pictRGB->sizeX; j++) {
			fscanf(picture, "%d", &pictRGB->matrixBlue[i][j]);
		}
	}
}

//======================================================================//

/**
 * \fn int storagePictureBW(PictureBW* pictBW, FILE* picture)
 * \brief Lecture du fichier .txt correspondant à l'image traitée
 * 	et stockage des valeurs lues dans la structure pictBW correspondante.
 * \param pictBW Structure représentative de l'image traitée.
 * \param log Fichier de log.
 */

int storagePictureBW(PictureBW* pictBW, FILE* picture) {
	// STOCKAGE TEMPORAIRE DE LA COMPOSANTE GRISE
	int i, j;
	
	// Matrice grey
	for(i = 0; i < pictBW->sizeY; i++) {
		for(j = 0; j < pictBW->sizeX; j++) {
			fscanf(picture, "%d", &pictBW->matrixGrey[i][j]);
		}
	}
}

//======================================================================//