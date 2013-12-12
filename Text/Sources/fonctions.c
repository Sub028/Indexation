#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "histogram.h"

//fonction servant a recuperer tous les mots sans les balises  -> GROOOS BUUUG !!! n'affiche pas les mots mais un gros espace !!!!
void get_words(FILE *file) { 
	char sentence[MAX_BUFFER_SIZE] = {0};
	char word[MAX_BUFFER_SIZE] = {0};
	int read = 0;
	int i, j;
	Histogram h;
	FILE *out = fopen("out.log", "w");
 
	init_histogram(&h);
	while(!feof(file)) {
		//On lit toute la ligne 
		fgets(sentence, MAX_BUFFER_SIZE, file);
		read = 0;
		for (i = 0, j = 0; i < MAX_BUFFER_SIZE; i++) {
			if (sentence[i] == '\n') {
				break;
			}
			if (sentence[i] == '<'  ) {
				read = 0;
			} 
			if(sentence[i] == '>' && sentence[i + 1] != '<') {
				read = 1;
				i++;
			}
			// si il s'agit d'un 'vrai' mot
 			if (read) {
				if(sentence[i] == '\n') {
					i++;
				}
 				if (sentence[i] != ' ') {
					word[j++] = sentence[i];
 				} else {
					printf("|%s| \n", word);
					addValue(word, &h);
					memset(word, 0, MAX_BUFFER_SIZE);
					j = 0;
 				}
 			}
 		}
 		display_histo(&h, out);
// 		fprintf(out, "%s", word);
		/*//afficher 'word[]'
		printf("word[] : ");
		for (j=0 ; j<MAX_BUFFER_SIZE; j++) {
			printf("%s", word[j]);	
		}*/
	}
	fclose(out);
}

//&& strlen(&sentence[i])<3 pour les mots de moins de 3 lettres


