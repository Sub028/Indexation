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
// - Structure picture
//======================================================================//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"

//======================================================================//

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