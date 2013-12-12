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