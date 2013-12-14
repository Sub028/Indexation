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
// - Ouverture d'une image (au format .txt)
// - Appel de la fonction de lecture et stockage temp des images
// - Fermeture de l'image ouverte
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