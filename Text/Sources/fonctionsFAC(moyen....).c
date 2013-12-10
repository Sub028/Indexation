#include <stdio.h>
#include <stdlib.h>

//mettre un cartouche au debut
//mettre des commentaires 

											ENTRE /**/ = NE SERT A RIEN !
/*
int renvoyer_nb_mots(File fic) {
	 int nb_mots = 0; 

	 // pr tt le fichier
	 while (fscanf(fic, "%c") != NULL) {
	 	// si il s'agit d'un 'vrai mot' (pas de balise)
	 	if (fgets(fic, "%c") == '<') {
	 		printf("a ne pas prendre !!!");
			// %*s ignore le mot 
	 		fscanf(f, "%*s", 
	 	}
	 	nb_mots++;
	 }
	return nb_mots;
}
*/

void contruire_descripteur(File fic, char descripteur[][]) {
	 
}

void afficher_descripteur(char desc[][]) {
	int i,j;
	for (i=0 ; i<longueur du tableau ; i++) {
		for (j=0 ; j<longueur du tableau ; j++) {
 			printf("%s - %i", desc[i][], desc[][]);
 		}
 	}
}

int main() {
	... (fopen fic...)
	int nb_mots = renvoyer_nb_mots(fic);
	int nb_occ = renvoyer_nb_occurences(fic);
	char tab_descripteur[nb_mots][nb_occ];

	contruire_descripteur();
	printf("Descripteur :\n");
	afficher_descripteur();
}
