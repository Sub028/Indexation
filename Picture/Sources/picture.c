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
// - Structure picture
//======================================================================//

#include "picture.h"

//======================================================================//

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

int initPictureBW(PictureBW* pictBW, int y, int x, char* filename, FILE* log) {
	pictBW->filename = (char*)malloc(sizeof(*filename));
	strcpy(pictBW->filename, filename);
	pictBW->sizeY = y;
	pictBW->sizeX = x;
	pictBW->component = 1;
	pictBW->matrixGrey = allocMatrix2D(pictBW->sizeY, pictBW->sizeX, log);	
}

//======================================================================//

int removePictureRGB(PictureRGB* pictRGB, FILE* log) {
	freeMatrix2D(pictRGB->matrixRed, pictRGB->sizeY, log);
	freeMatrix2D(pictRGB->matrixGreen, pictRGB->sizeY, log);
	freeMatrix2D(pictRGB->matrixBlue, pictRGB->sizeY, log);
}

//======================================================================//

int removePictureBW(PictureBW* pictBW, FILE* log) {
	freeMatrix2D(pictBW->matrixGrey, pictBW->sizeY, log);
}

//======================================================================//