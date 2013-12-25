//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: ZERBIB Yoanna
// Date de création: 18/11/13
//======================================================================//
// Fichier C: parser.c
//======================================================================//
// Module TEXTES:
// - Indexation des textes (.xml)
//======================================================================//

#include "parser.h"

//fonction servant a recuperer tous les mots sans les balises
void get_words(FILE *file) { 
	char sentence[MAX_BUFFER_SIZE] = {0};
	char word[MAX_BUFFER_SIZE] = {0};
	int read = 0;
	int i, j;
	Histogram h;
// 	desciptorBase = fopen("Bases/liste_base_audio.base", "a+");
// 	FILE *soundBase = fopen("Bases/base_descripteur_audio.base", "a");
	FILE *out = fopen("Resultats/Histogram.out", "a+");
	FILE *out2 = fopen("Resultats/Descriptor.out", "a+");

// 	desciptorBase = fopen("Bases/liste_base_text.base", "a+");
// 	if(desciptorBase == NULL) {
// 		system("mkdir Bases");
// 		desciptorBase = fopen("Bases/liste_base_text.base", "a+");
// 	}
	init_histogram(&h);
	while(!feof(file)) {
		// On lit toute la ligne 
		fgets(sentence, MAX_BUFFER_SIZE, file);
		read = 0;
		for (i = 0, j = 0; i < MAX_BUFFER_SIZE; i++) {
			if (sentence[i] == '\n') {
				break;
			}
			if (sentence[i] == '<') {
				read = 0;
			} 
			if(sentence[i] == '>' && sentence[i+1] != '<' ) {
				read = 1;
				i++;
			}
			// s'il s'agit d'un 'vrai' mot
 			if (read) {
 				sentence[i] = tolower(sentence[i]);
 				//replace_bad_letters(sentence[i]);
				if(sentence[i] == '\n') {
					break;
				}
 				if (sentence[i] != ' ' && sentence[i] != ',' && sentence[i] != '.' && sentence[i+1] != '<') {
					word[j] = sentence[i];
					j++;
				}
				//le mot est fini
 				else {
	 				if (good_word(word)) {
						add_value(word, &h);
					}
					j = 0;
					memset(word, 0, MAX_BUFFER_SIZE);
	 			}
 			}
 		}
	}
	display_histogram(&h, out);
	display_descriptor(&h, out2);
	add_list_base_descriptors();
	free_descriptor(&h);
	fclose(out);
}

//fonction qui ne garde que les 'bons' mots
int good_word(char* word) {
	int res = 1;
	int i = 0;
	int der_lettre = strlen(word)-1;
	char *ptr_virgule = strchr(word, ',');
	char *ptr_point = strchr(word, '.');
		
	//si le premier caractere est une ponctuation
	if (ispunct(word[i])) {
		word[i] = word[i+1];
	}
	//si le 2eme caractere est une apostrophe (s'appelait)
	if (word[1] == '\'') {
		for (i = 0 ; i < strlen(word) ; i++) {
			word[i] = word[i+2];
		}
	}
	//si le 3eme caractere est une apostrophe (qu'il)
	if (word[2] == '\'') {
		for (i = 0 ; i < strlen(word) ; i++) {
			word[i] = word[i+3];
		}
	}
	//si le mot fait moins de NB_MAX_WORDS caracteres
	if (strlen(word) <= NB_MAX_WORDS) {
		res = 0;
	} 
	//si le mot est un pronom ou un article (ou n'importe quel autre mot n'ayant aucune importance)
	if (strcmp(word, "un") == 0 || strcmp(word, "une") == 0 || strcmp(word, "de") == 0 || strcmp(word, "des") == 0 || strcmp(word, "le") == 0 || strcmp(word, "la") == 0 || strcmp(word, "les") == 0 || strcmp(word, "je") == 0 || strcmp(word, "me") == 0 || strcmp(word, "se") == 0 || strcmp(word, "te") == 0 ) {
		res = 0;
	}	
	
	return res;
}


void replace_bad_letters(char c) {
	//pour mettre la premiere lettre en minuscule
	c = tolower(c); 
/*
	//pour enlever les accents
	if (c == 'à') {
		c = 'a';
	}
	if (c == 'é' || c == 'è' || c == 'ê' || c == 'ë') {
		c = 'e';
	}
	if (c == 'ù') {
		c = 'u';
	}
	*/
}
