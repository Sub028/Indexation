#include <stdio.h>
#include <stdlib.h>
#include "histogram.h"

int main(int argc, char *argv[]) {
	//tableau qui va contenir une phrase
	char sentence[MAX_BUFFER_SIZE] = {0};

	//les cas d'erreur
	if (argc < 2) {
		printf("Nom du fichier requis\n");
	return (EXIT_FAILURE);

	}
	FILE *fic = fopen(argv[1], "r");
	
	if (fic == NULL) {
		printf("Erreur lors de l'ouverture du fichier\n");
		return (EXIT_FAILURE);
	}

	//l'indexation
	//fscanf(fic, "<%s>%s", string, string2);
	get_words(fic);
	//addValue(...);
	//display_descriptor();
	//pour liberer memoire du decripteur
	//free_descriptor();
	//on ferme le fichier
	fclose(fic);
	return(EXIT_SUCCESS);
}


