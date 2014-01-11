//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: VEILLARD Aurélien
// Date de création: 30/11/13
//======================================================================//
// Fichier C: openPicture.c
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
 * \file openPicture.c
 * \author Aurélien Veillard
 * \brief Traitement complet de l'image.
 * \version 1.0
 * \date 30 Novembre 2013
 * 
 * Permet d'ouvrir une image, de la stocker puis de créer un histogramme en la quantifiant.
 */

//======================================================================//

#include <sys/types.h>
#include <sys/stat.h>
#include "openPicture.h"
#include "Utility/utility.h"

//======================================================================//

/**
 * \fn int openPict(FILE* picture, FILE* log, FILE* descriptorBase, char* filename)
 * \brief Appel les fonctions de traitement et de stockage de l'image
 * \param picture L'image ouverte est en cours de traitement.
 * \param log Fichier de log.
 * \param descriptorBase Fichier descripteur.
 * \param filename Le nom de l'image à ouvrir.
 */

int openPict(FILE* picture, FILE* log, FILE* descriptorBase, char* filename) {
	struct stat st;
	PictureRGB pictRGB;
	PictureBW pictBW;
	Histogram hist;
	Quantification quant;
	time_t clock;
	int sizeXTemp, sizeYTemp, nbComponent;
	char id[100];
	
	FILE* pictureBase = fopen("Bases/base_descripteur_image.base", "a+");
	sprintf(id, "ID%d", rand());

	if(stat(filename, &st) == -1) {
		fprintf(log, "STAT ERROR ");
		return(-1);
	}
	
	// Allocation de la mémoire pour stocker l'image
	fscanf(picture, "%d %d %d", &sizeYTemp, &sizeXTemp, &nbComponent);
	
	if(getValueOf("NB_SIGNIFICANT_BIT_FOR_QUANTIFICATION", &quant.nbBit) == -1) {
		fprintf(log, "CONFIG ERROR ");
		return(-1);
	}
	
	if(nbComponent == 3) {		
		// Création d'une image temporaire (initialisation)
		initPictureRGB(&pictRGB, sizeYTemp, sizeXTemp, filename, log);
		
		// Création d'un histogramme RGB temporaire (initialisation)
		initHistogram(&hist, pow(2, (quant.nbBit*3)), log);
		
		// Stockage temporaire de l'image
		storagePictureRGB(&pictRGB, picture);
		
		// Calcul de la quantification
		calculateMatrixRGBQuantification(&pictRGB, &quant, &hist, filename);
		
		// Ecriture histogramme
		strcat(id, "-");
		strcat(id, pictRGB.filename);
		time(&clock);
		fprintf(pictureBase, "%s\t%d\t%d\t%s\t%s", id, 2, (int)pow(2, quant.nbBit * 3), "picture", ctime(&st.st_mtime));
		writingHistogram(&hist, pictureBase, (quant.nbBit*3));
		
		// Suppression de l'histogramme temporaire
		removeHistogram(&hist, log);
		
		// Suppression de l'image temporaire
		removePictureRGB(&pictRGB, log);
	} else if (nbComponent == 1) {
		// Création d'une image BW temporaire (initialisation)
		initPictureBW(&pictBW, sizeYTemp, sizeXTemp, filename, log); 
		
		// Création d'un histogramme BW temporaire (initialisation)
		initHistogram(&hist, pow(2, quant.nbBit), log);
		
		// Stockage temporaire de l'image
		storagePictureBW(&pictBW, picture);
		
		// Calcul de la quantification
		calculateMatrixBWQuantification(&pictBW, &quant, &hist, filename);
		
		// Ecriture histogramme
		strcat(id, "-");
		strcat(id, pictBW.filename);
		time(&clock);
		fprintf(pictureBase, "%s\t%d\t%d\t%s\t%s", id, 2, (int)pow(2, quant.nbBit), "picture", ctime(&st.st_mtime));
		writingHistogram(&hist, pictureBase, quant.nbBit);
		
		// Suppression de l'histogramme temporaire
		removeHistogram(&hist, log);
		
		// Suppression de l'image temporaire
		removePictureBW(&pictBW, log);		
	} else {
		fprintf(log, "ERROR: number of component of the picture is incorrect (components = %d)\n", nbComponent);
		fflush(stdout);
	}
	fprintf(descriptorBase, "%s\t%s\n", filename, id);
}

//======================================================================//