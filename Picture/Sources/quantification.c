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

#include "quantification.h"

//======================================================================//

int quantifyRGB(Quantification* quant, int RedValue, int GreenValue, int BlueValue) {
	int powerOfTwo, exponent, positionQuantWord;
	
	if(RedValue <= 255 && GreenValue <= 255 && BlueValue <= 255) {
		quant->quantifyingNumber = (int*)malloc(((quant->nbBit)*3)*sizeof(int));
	
		// Composante Rouge
		positionQuantWord = 0;
		for(exponent = 7; exponent >= (8-quant->nbBit); exponent--) {	// exponent = 7 pour un int de 8 le MSB vaut 2^7
			powerOfTwo = pow(2, exponent);	// Deux à la puissance exponent
			if((RedValue%powerOfTwo) <= (RedValue-1)) {	// Si le modulo du nombre par la puissance de deux est inférieur au nombre moins un alors le nombre contient cette puissance de deux
				quant->quantifyingNumber[positionQuantWord] = 1;
				RedValue -= powerOfTwo;	// Si la puissance de deux est contenu alors on la retranche au nombre pour poursuivre le traitement
			} else {
				quant->quantifyingNumber[positionQuantWord] = 0;
			}
			positionQuantWord++;
		}
	
		for(exponent = 7; exponent >= (8-quant->nbBit); exponent--) {	// exponent = 7 pour un int de 8 le MSB vaut 2^7
			powerOfTwo = pow(2, exponent);	// Deux à la puissance exponent
			if((GreenValue%powerOfTwo) <= (GreenValue-1)) {	// Si le modulo du nombre par la puissance de deux est inférieur au nombre moins un alors le nombre contient cette puissance de deux
				quant->quantifyingNumber[positionQuantWord] = 1;
				GreenValue -= powerOfTwo;	// Si la puissance de deux est contenu alors on la retranche au nombre pour poursuivre le traitement
			} else {
				quant->quantifyingNumber[positionQuantWord] = 0;
			}
			positionQuantWord++;
		}
	
		for(exponent = 7; exponent >= (8-quant->nbBit); exponent--) {	// exponent = 7 pour un int de 8 le MSB vaut 2^7
			powerOfTwo = pow(2, exponent);	// Deux à la puissance exponent
			if((BlueValue%powerOfTwo) <= (BlueValue-1)) {	// Si le modulo du nombre par la puissance de deux est inférieur au nombre moins un alors le nombre contient cette puissance de deux
				quant->quantifyingNumber[positionQuantWord] = 1;
				BlueValue -= powerOfTwo;	// Si la puissance de deux est contenu alors on la retranche au nombre pour poursuivre le traitement
			} else {
				quant->quantifyingNumber[positionQuantWord] = 0;
			}
			positionQuantWord++;
		}
	} else {
		printf("> ERROR: RGB level higher than 255: value = R: %d / G: %d / B: %d\n", RedValue, GreenValue, BlueValue);
		fflush(stdout);
		return -1;
	}
}

//======================================================================//

int quantifyBW(Quantification* quant, int GreyValue) {
	int powerOfTwo, exponent, positionQuantWord;
	
	if(GreyValue <= 255) {
		quant->quantifyingNumber = (int*)malloc((quant->nbBit)*sizeof(int));
	
		// Composante Rouge
		positionQuantWord = 0;
		for(exponent = 7; exponent >= (8-quant->nbBit); exponent--) {	// exponent = 7 pour un int de 8 le MSB vaut 2^7
			powerOfTwo = pow(2, exponent);	// Deux à la puissance exponent
			if((GreyValue%powerOfTwo) <= (GreyValue-1)) {	// Si le modulo du nombre par la puissance de deux est inférieur au nombre moins un alors le nombre contient cette puissance de deux
				quant->quantifyingNumber[positionQuantWord] = 1;
				GreyValue -= powerOfTwo;	// Si la puissance de deux est contenu alors on la retranche au nombre pour poursuivre le traitement
			} else {
				quant->quantifyingNumber[positionQuantWord] = 0;
			}
			positionQuantWord++;
		}
	} else {
		printf("> ERROR: Grey level higher than 255: value = %d\n", GreyValue);
		fflush(stdout);
		return -1;
	}
}	

//======================================================================//