//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: VEILLARD Aurélien
// Date de création: 18/11/13
//======================================================================//
// Fichier C: openFolder.c
//======================================================================//
// Fonctions:
// - 
//======================================================================//

/**
 * \file openFolder.c
 * \author Aurélien Veillard
 * \brief Permet de tester le module Image.
 * \version 1.0
 * \date 18 Novembre 2013.
 */

//======================================================================//

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "openPicture.h"

//======================================================================//

int main(int argc, char* argv[]) {
	DIR* folder = NULL;
	FILE* fileList = NULL;
	FILE* folderList = NULL;
	FILE* picture = NULL;
	FILE* log = NULL;
	FILE* descriptorBase = NULL;
	char folderReadFromList[100] = {};
	char fileReadFromList[100] = {};
	char pathFolder[100] = {};
	struct dirent* readdingFile = NULL;
	int isEndOfFile = 0, isAlreadyContain = 0;
	
	if(argc < 2) {
		fprintf(stderr, "\033[31m");
		fprintf(stderr, "> Bad utilisation: need filename\n");
		fprintf(stderr, "\033[00m");
		return EXIT_FAILURE; 
	}
	
	folder = opendir(argv[1]);
	
	descriptorBase = fopen("Bases/liste_base_image.base", "a+");
	if(descriptorBase == NULL) {
		system("mkdir Bases");
		descriptorBase = fopen("Bases/liste_base_image.base", "a+");
	}
	
	log = fopen("log.log", "a");
	
	fileList = fopen("Temp/liste_fichiers.list", "a+");
	if(fileList == NULL) {
		system("mkdir Temp");
		fileList = fopen("Temp/liste_fichiers.list", "a+");
	}
	folderList = fopen("Temp/liste_dossiers.list", "a+");
	
	srand(time(NULL));
	
	while ((readdingFile = readdir(folder)) != NULL) {
		// Si le fichier lu est différent de '.' '..' et ne contient pas '~' alors on peut le traiter
		if(strcmp(readdingFile->d_name, ".") != 0 && strcmp(readdingFile->d_name, "..") != 0 && strchr(readdingFile->d_name, '~') == NULL) {
			// Si le fichier n'a pas d'extension (donc ne contient pas de '.') alors c'est un dossier attention quand même!
			if((strchr(readdingFile->d_name, '.')) == NULL) {
				// TODO Permet de récupérer les noms des dossiers qui ne sont pas déja dans la liste
				// Mais ne fonctionne pas très bien avec des noms de dossiers composés
				do {
					isEndOfFile = fscanf(folderList, "%s\n", folderReadFromList);
					if(strcmp(folderReadFromList, readdingFile->d_name) == 0) {
						isAlreadyContain = 1;
					}
				} while(isEndOfFile != EOF && isAlreadyContain == 0);
				if(!isAlreadyContain) {
					fprintf(folderList, "%s\n", readdingFile->d_name);
				}
				isAlreadyContain = 0;
			// Sinon c'est un fichier
			} else {
				// Si le nom du fichier image fini pas un 't' alors c'est surement un ".txt" 
				// TODO Trouver un meilleur moyen pour détecter les .txt
				if(strrchr(readdingFile->d_name, 't') != 0){
					// TODO Améliorer car ne fonctionne pas avec des noms de fichiers composés
					do {
						isEndOfFile = fscanf(fileList, "%s\n", fileReadFromList);
						if(strcmp(fileReadFromList, readdingFile->d_name) == 0) {
							isAlreadyContain = 1;
						}
					} while(isEndOfFile != EOF && isAlreadyContain == 0);
					if(!isAlreadyContain) {
						fprintf(fileList, "%s\n", readdingFile->d_name);
					}
				}
			}
		}
	}
	
	rewind(fileList);
	
	while(fscanf(fileList, "%s\n", fileReadFromList) != EOF) {
		strcpy(pathFolder, argv[1]);
		strcat(pathFolder, "/");
		strcat(pathFolder, fileReadFromList);
		picture = fopen(pathFolder, "r");
		if(picture != NULL) {
			fprintf(log, "> Openning success: %s\n", pathFolder);
			openPict(picture, log, descriptorBase, pathFolder);
			fprintf(log, "> Indexation of '%s' done!\n", argv[1]);
			fclose(picture);
			fprintf(log, "> Closing: %s\n", pathFolder);
		} else if(picture == NULL) {
			fprintf(log, "> ERROR: can't open picture\n");
		}
	}
	
	fclose(descriptorBase);
	fclose(log);
	fclose(fileList);
	fclose(folderList);
	closedir(folder);
}
