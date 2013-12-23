//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: VEILLARD Aurélien
// Date de création: 30/11/13
//======================================================================//
// Fichier H: openPicture.h
//======================================================================//
// Fonctions:
// 	- Ouverture d'une image (au format .txt)
// 	- Lecture
//	- Stockage temporaire d'une image
//	- Quantification
//	- Ecriture de l'histogramme dans un fichier descripteur
//	- Fermeture de l'image ouverte
//======================================================================//

/**
 * \file openPicture.h
 * \author Aurélien Veillard
 * \brief Permet d'ouvrir une image, de la stocker temporairement,
 * 	puis d'effectuer une quantification qui sera stockée dans un histogramme.
 * \version 1.0
 * \date 30 Novembre 2013
 */

//======================================================================//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "picture.h"
#include "matrix.h"
#include "histogram.h"
#include "quantification.h"

//======================================================================//

int openPict(FILE* picture, FILE* log, FILE* descriptorBase, char* filename);

//======================================================================//