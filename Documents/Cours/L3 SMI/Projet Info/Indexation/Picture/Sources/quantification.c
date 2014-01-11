//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: VEILLARD Aurélien
// Date de création: 06/12/13
//======================================================================//
// Fichier C: quantification.c
//======================================================================//
// Fonctions:
// 	- Récupère les n premiers bits des int des composantes RGB ou BW
//	- Stockage dans un tableau de la taille nbBit*nbComponent
//	
//	Pour les RGB:
//			    size = ((quant->nbBit)*3)
//		       ___________________________________
// quantifyingNumber = [ ] [ ] ... [ ] [ ] ... [ ] [ ] ...
//		 	^   ^	    ^   ^       ^   ^
// 	      	     MSBs rouges  MSBs verts  MSBs bleus
//
//	Pour les BW: idem sauf pour une seule composante
//======================================================================//

/**
 * \file quantification.c
 * \author Aurélien Veillard
 * \brief Permet de quantifier une image complète.
 * \version 1.0
 * \date 06 Décembre 2013
 * 
 * A chaque appel, l'image donnée en paramètre est traitée pixel par pixel.
 */

//======================================================================//

#include "quantification.h"

//======================================================================//

/**
 * \fn int quantifyRGB(Quantification* quant, int redValue, int greenValue, int blueValue)
 * \brief Calcul de la quantification d'un pixel.
 * \param quant Structure quant contenant le résultat.
 * \param redValue Composante rouge.
 * \param greenValue Composante verte.
 * \param blueValue Composante bleue.
 */

int quantifyRGB(Quantification* quant, int redValue, int greenValue, int blueValue, char* filename) {
	int powerOfTwo, exponent, positionQuantWord;
	
	if(redValue <= 255 && greenValue <= 255 && blueValue <= 255) {	// Test pour savoir si les valeurs lues sont correctes
		quant->quantifyingNumber = (int*)malloc(((quant->nbBit)*3)*sizeof(int));	// Allocation du tableau qui contiendra le résultat
		positionQuantWord = 0;	// Initialisation de l'indice permettant de parcourir le tableau précédemment alloué
		
		// Composante Rouge		
		for(exponent = 7; exponent >= (8-quant->nbBit); exponent--) {	// exponent = 7 pour un int de 8 le MSB vaut 2^7
			powerOfTwo = pow(2, exponent);	// Deux à la puissance exponent
			if((redValue%powerOfTwo) <= (redValue-1)) {	// Si le modulo du nombre par la puissance de deux est inférieur au nombre moins un, alors le nombre contient cette puissance de deux
				quant->quantifyingNumber[positionQuantWord] = 1;	// Alors on passe a un le bit correspondant dans le tableau quantifyingNumber
				redValue -= powerOfTwo;	// Si la puissance de deux est contenu alors on la retranche au nombre pour poursuivre le traitement
			} else {
				quant->quantifyingNumber[positionQuantWord] = 0;	// Sinon on passe le bit à zéro
			}
			positionQuantWord++;	// Permet de se déplacer d'une case dans le tableau
		}
	
		// Composante Verte
		for(exponent = 7; exponent >= (8-quant->nbBit); exponent--) {	// exponent = 7 pour un int de 8 le MSB vaut 2^7
			powerOfTwo = pow(2, exponent);	// Deux à la puissance exponent
			if((greenValue%powerOfTwo) <= (greenValue-1)) {	// Si le modulo du nombre par la puissance de deux est inférieur au nombre moins un, alors le nombre contient cette puissance de deux
				quant->quantifyingNumber[positionQuantWord] = 1;	// Alors on passe a un le bit correspondant dans le tableau quantifyingNumber
				greenValue -= powerOfTwo;	// Si la puissance de deux est contenu alors on la retranche au nombre pour poursuivre le traitement
			} else {
				quant->quantifyingNumber[positionQuantWord] = 0;	// Sinon on passe le bit à zéro
			}
			positionQuantWord++;	// Permet de se déplacer d'une case dans le tableau
		}
	
		// Composante Bleu
		for(exponent = 7; exponent >= (8-quant->nbBit); exponent--) {	// exponent = 7 pour un int de 8 le MSB vaut 2^7
			powerOfTwo = pow(2, exponent);	// Deux à la puissance exponent
			if((blueValue%powerOfTwo) <= (blueValue-1)) {	// Si le modulo du nombre par la puissance de deux est inférieur au nombre moins un, alors le nombre contient cette puissance de deux
				quant->quantifyingNumber[positionQuantWord] = 1;	// Alors on passe a un le bit correspondant dans le tableau quantifyingNumber
				blueValue -= powerOfTwo;	// Si la puissance de deux est contenu alors on la retranche au nombre pour poursuivre le traitement
			} else {
				quant->quantifyingNumber[positionQuantWord] = 0;	// Sinon on passe le bit à zéro
			}
			positionQuantWord++;	// Permet de se déplacer d'une case dans le tableau
		}
	} else {
		fprintf(stderr, "\033[31m");
		fprintf(stderr, "> ERROR: RGB level higher than 255: value = R: %d / G: %d / B: %d (in file: %s)\n", redValue, greenValue, blueValue, filename);
		fprintf(stderr, "\033[00m");
		fflush(stdout);
		return -1;
	}
}

//======================================================================//

/**
 * \fn int quantifyBW(Quantification* quant, int greyValue)
 * \brief Calcul de la quantification d'un pixel.
 * \param quant Structure quant contenant le résultat.
 * \param greyValue Composante grise.
 */

int quantifyBW(Quantification* quant, int greyValue, char* filename) {
	int powerOfTwo, exponent, positionQuantWord;
	
	if(greyValue <= 255) {
		quant->quantifyingNumber = (int*)malloc((quant->nbBit)*sizeof(int));
		positionQuantWord = 0;	// Initialisation de l'indice permettant de parcourir le tableau précédemment alloué
		
		// Composante Noir et blanc
		for(exponent = 7; exponent >= (8-quant->nbBit); exponent--) {	// exponent = 7 pour un int de 8 le MSB vaut 2^7
			powerOfTwo = pow(2, exponent);	// Deux à la puissance exponent
			if((greyValue%powerOfTwo) <= (greyValue-1)) {	// Si le modulo du nombre par la puissance de deux est inférieur au nombre moins un alors le nombre contient cette puissance de deux
				quant->quantifyingNumber[positionQuantWord] = 1;	// Alors on passe a un le bit correspondant dans le tableau quantifyingNumber
				greyValue -= powerOfTwo;	// Si la puissance de deux est contenu alors on la retranche au nombre pour poursuivre le traitement
			} else {
				quant->quantifyingNumber[positionQuantWord] = 0;	// Sinon on passe le bit à zéro
			}
			positionQuantWord++;	// Permet de se déplacer d'une case dans le tableau
		}
	} else {
		fprintf(stderr, "\033[31m");
		fprintf(stderr, "> ERROR: Grey level higher than 255: value = %d (in file: %s)\n", greyValue, filename);
		fprintf(stderr, "\033[00m");
		fflush(stdout);
		return -1;
	}
}	

//======================================================================//

/**
 * \fn int calculateMatrixRGBQuantification(PictureRGB* pictRGB, Quantification* quant, Histogram* hist)
 * \brief Calcul de la quantification d'une image.
 * \param pictRGB Permet d'utiliser les matrices de stockage temporaires de l'image couleurs.
 * \param quant Structure contenant le résultat temporaire de la quantification d'un pixel.
 * \param hist Structure contenant l'histogramme.
 */

int calculateMatrixRGBQuantification(PictureRGB* pictRGB, Quantification* quant, Histogram* hist, char* filename) {
	int i, j, k, exponent, quantifyingLevel;
	int redValue, blueValue, greenValue;
	
	// Traitement sur l'image
	for(i = 0; i < pictRGB->sizeY; i++) {		// Parcours de la matrice en ligne
		for(j = 0; j < pictRGB->sizeX; j++) {	// Parcours de la matrice en colonne
			// Quantification
			redValue = pictRGB->matrixRed[i][j];		// Mémorisation temporaire de la composante rouge du pixel en cours de traitement
			greenValue = pictRGB->matrixGreen[i][j];	// Mémorisation temporaire de la composante rouge du pixel en cours de traitement
			blueValue = pictRGB->matrixBlue[i][j];		// Mémorisation temporaire de la composante rouge du pixel en cours de traitement
			quantifyRGB(&(*quant), redValue, greenValue, blueValue, filename);	// Appel de la fonction de calcul de la quantification
			
			// Transformation du résultat de quantification
			exponent = ((quant->nbBit)*(pictRGB->component)) - 1;	// Calcul de l'exposant maximal en fonction du nombre de bit de quantification
			quantifyingLevel = 0;	// Initialisation de la variable qui contiendra le résultat
			
			for(k = 0; k < ((quant->nbBit)*(pictRGB->component)); k++) {	// Parcours du tableau de la gauche vers la droite (du poids fort au poids faible)
				if(quant->quantifyingNumber[k] == 1) {	// Si le bit est a 1 alors on ajoute "son poids" au résultat
					quantifyingLevel += pow(2, exponent);	// Ajout du poids du bit à un 1
				}
				exponent--;	// Diminution du rang de l'exposant
			}
			hist->matrixHisto[1][quantifyingLevel]++;	// Incrémentation de la case de l'histogramme correspondant (car classé de 0 à n-1) à la valeur calculée
		}
	}
}

//======================================================================//

/**
 * \fn int calculateMatrixBWQuantification(PictureBW* pictBW, Quantification* quant, Histogram* hist)
 * \brief Calcul de la quantification d'une image.
 * \param pictBW Permet d'utiliser la matrice de stockage temporaire de l'image noir et blanc.
 * \param quant Structure contenant le résultat temporaire de la quantification d'un pixel.
 * \param hist Structure contenant l'histogramme.
 */

int calculateMatrixBWQuantification(PictureBW* pictBW, Quantification* quant, Histogram* hist, char* filename) {
	int i, j, k, exponent, quantifyingLevel;
	int greyValue;
	
	// Traitement sur l'image
	for(i = 0; i < pictBW->sizeY; i++) {		// Parcours de la matrice en ligne
		for(j = 0; j < pictBW->sizeX; j++) {	// Parcours de la matrice en colonne
			// Quantification
			greyValue = pictBW->matrixGrey[i][j];	// Mémorisation temporaire de la composante noir et blanc du pixel en cours de traitement
			quantifyBW(&(*quant), greyValue, filename);	// Appel de la fonction de calcul de la quantification
			
			// Transformation du résultat de quantification
			exponent = quant->nbBit - 1;	// Calcul de l'exposant maximal en fonction du nombre de bits de quantification
			quantifyingLevel = 0;	// Initialisation de la variable qui contiendra le résultat
			
			for(k = 0; k < ((quant->nbBit)*(pictBW->component)); k++) {	// Parcours du tableau de la gauche vers la droite (du poids fort au poids faible)
				if(quant->quantifyingNumber[k] == 1) {	// Si le bit est a 1 alors on ajoute "son poids" au résultat
					quantifyingLevel += pow(2, exponent);	// Ajout du poids du bit à un 1
				}
				exponent--;	// Diminution du rang de l'exposant
			}
			hist->matrixHisto[1][quantifyingLevel]++;	// Incrémentation de la case de l'histogramme correspondant (car classé de 0 à n-1) à la valeur calculée
		}
	}
}

//======================================================================//