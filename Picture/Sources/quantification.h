//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: VEILLARD Aurélien
// Date de création: 06/12/13
//======================================================================//
// Fichier H: quantification.h
//======================================================================//
// Fonctions:
// 	- Récupère les n premiers bits des int des composantes RGB ou BW
//	- Stockage dans un tableau de la taille nbBit*nbComponent
//======================================================================//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "picture.h"
#include "matrix.h"
#include "histogram.h"

//======================================================================//

typedef struct {
	int* quantifyingNumber;
	int nbBit;	// Nombre de bit (de poids fort) à récupérer par composante (donner par le configurateur)
} Quantification;

//======================================================================//

int quantifyRGB(Quantification* quant, int RedValue, int GreenValue, int BlueValue);
int quantifyBW(Quantification* quant, int GreyValue);
int calculateMatrixRGBQuantification(PictureRGB* pictRGB, Quantification* quant, Histogram* hist);
int calculateMatrixBWQuantification(PictureBW* pictBW, Quantification* quant, Histogram* hist);

//======================================================================//