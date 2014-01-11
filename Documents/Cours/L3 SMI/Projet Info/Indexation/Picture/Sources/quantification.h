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

/**
 * \file quantification.h
 * \author Aurélien Veillard
 * \brief Permet de quantifier une image complète.
 * \version 1.0
 * \date 06 Décembre 2013
 * 
 * A chaque appel, l'image donnée en paramètre est traitée pixel par pixel.
 */

//======================================================================//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "picture.h"
#include "matrix.h"
#include "histogram.h"

//======================================================================//

/**
 * \struct Quantification
 * \brief Stockage temporairement du résultat de quantification.
 * 
 * Cette structure permet de stocker temporairement le résultat de la quantification d'un pixel couleur ou noir et blanc.
 * 
 * La structure est composée: 
 * 	- d'un tableau alloué dynamiquement en fonction du type d'image (couleur ou noir et blanc) et le nombre de bit de quantification. La taille du tableau est donnée par l'équation suivante: (nombre de bits de quantification) x (nombre de composantes).
 *	
 * 	- d'un entier contenant le nombre de bit de quantification, c'est à dire le nombre de bits de poids forts à conserver. 
 */

typedef struct {
	int* quantifyingNumber;
	int nbBit;	// Nombre de bit (de poids fort) à récupérer par composante (donner par le configurateur)
} Quantification;

//======================================================================//

int quantifyRGB(Quantification* quant, int RedValue, int GreenValue, int BlueValue, char* filename);
int quantifyBW(Quantification* quant, int GreyValue, char* filename);
int calculateMatrixRGBQuantification(PictureRGB* pictRGB, Quantification* quant, Histogram* hist, char* filename);
int calculateMatrixBWQuantification(PictureBW* pictBW, Quantification* quant, Histogram* hist, char* filename);

//======================================================================//