//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: VEILLARD Aurélien
// Date de création: 18/11/13
//======================================================================//
// Fichier H: picture.h
//======================================================================//
// Fonctions:
//	- Initialisation de la structure image couleur et blanc/noir
//	- Destruction de la structure temporaire
//	- Stockage temporaire de l'image
//======================================================================//

/**
 * \file picture.h
 * \author Aurélien Veillard
 * \brief Permet d'initialiser une structure de type image qui contient 1 ou 3 matrice(s)
 * 	représentative(s) de l'image traitée, suppression de l'image, stockage temporaire de l'image.
 * \version 1.0
 * \date 18 Novembre 2013
 */

//======================================================================//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"

//======================================================================//

/**
 * \struct PictureRGB
 * \brief Structure représentative d'une image couleur (RGB).
 *	Permet de stocker les matrices RGB, la taille, le nombre de composantes et le nom.
 */

#ifndef PICTURE_RGB
#define PICTURE_RGB
typedef struct {
	char* filename;
	int sizeX;
	int sizeY;
	int component;
	int** matrixRed;
	int** matrixGreen;
	int** matrixBlue;
} PictureRGB; 	// Color picture
#endif /* PICTURE_RGB */

//======================================================================//

/**
 * \struct PictureBW
 * \brief Structure représentative d'une image noir et blanc (BW).
 *	Permet de stocker la matrice BW, la taille, le nombre de composantes et le nom.
 */

#ifndef PICTURE_BW
#define PICTURE_BW
typedef struct {
	char* filename;
	int sizeX;
	int sizeY;
	int component;
	int** matrixGrey;
} PictureBW; 	// Black and White picture (or greyscale picture)
#endif /* PICTURE_BW */

//======================================================================//

int initPictureRGB(PictureRGB* pictRGB, int sizeY, int sizeX, char* filename, FILE* log);
int initPictureBW(PictureBW* pictBW, int sizeY, int sizeX, char* filename, FILE* log);
int removePictureRGB(PictureRGB* pictRGB, FILE* log);
int removePictureBW(PictureBW* pictBW, FILE* log);
int storagePictureRGB(PictureRGB* pictRGB, FILE* picture);
int storagePictureBW(PictureBW* pictBW, FILE* picture);

//======================================================================//