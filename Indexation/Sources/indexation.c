#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include "Sound/wavFile.h"
#include "Picture/openPicture.h"

int main(int argc, char *argv[]) {
	struct dirent *currentElement;
	DIR *data;
	WavFile wavFile;
	char extension[BUFFER_SIZE] = {0};
	char buffer[BUFFER_SIZE] = {0};
	char path[BUFFER_SIZE] = {0};
	char id[BUFFER_SIZE] = {0};
	FILE *descriptorBaseSound;
	FILE *descriptorBaseTexts;
	FILE *descriptorBasePictures;
	FILE *log;
	FILE *currentPicture;
	FILE *currentText;
	int ret;
	time_t aclock;

	time(&aclock);

	data = opendir("Data/");
	if(data == NULL) {
		perror("Probleme lors de l'ouverture du dossier ");
		return(EXIT_FAILURE);
	}
	descriptorBaseSound = fopen("Bases/liste_base_audio.base", "a+");
	if(descriptorBaseSound == NULL) {
		system("mkdir Bases");
		descriptorBaseSound = fopen("Bases/liste_base_audio.base", "a+");
	}
	descriptorBasePictures = fopen("Bases/liste_base_image.base", "a+");
	descriptorBaseTexts = fopen("Bases/liste_base_text.base", "a+");

	log = fopen("log.log", "a");
	fprintf(log, "%s", ctime(&aclock));

	checkDescriptorBase(descriptorBaseSound, log, "sound");
	checkDescriptorBase(descriptorBasePictures, log, "image");
	checkDescriptorBase(descriptorBaseTexts, log, "text");
	while((currentElement = readdir(data))) {
		extractExtension(currentElement->d_name, extension);
		if(strcmp(extension, ".wav") == 0) {
			createPath(currentElement->d_name, "Data/", extension, path);
			fprintf(log, "OPPENING FILE : %s \t ", path);
			if(!getIdInDescriptorBase(descriptorBaseSound, id, path)) {
				openWavFile(&wavFile, path);
				if(writeDescriptor(&wavFile, descriptorBaseSound, log) == -1) {
					fprintf(log, " : WRITING SOUND DATA FAIL ! \n");
					continue;
				}
				fprintf(log, "FILE INDEXED ! \n");
				closeWavFile(&wavFile);
			} else {
				ret = getIfFileHasModified(id, path, log, "sound");
				if(ret == 1) {
					fprintf(log, "FILE ALLREADY INDEXED ! \n");
				} else if(ret == -1){
					fprintf(log, "READ DESCRIPTOR FAIL ! \n");
				} else {
					memset(buffer, 0, BUFFER_SIZE);
					sprintf(buffer, "%s\t%s\n", path, id);
					supprDescriptorHeader(descriptorBaseSound, buffer, "sound");
					supprDescriptor(id, "sound");
					openWavFile(&wavFile, path);
					if(writeDescriptor(&wavFile, descriptorBaseSound, log) == -1) {
						fprintf(log, " : WRITING DATA FAIL ! \n");
						continue;
					}
					closeWavFile(&wavFile);
					fprintf(log, "FILE HAS BEEN MODIFIED ! \n");
				}
			}
			
		/**
		 * Fichier image sous forme de texte
		 */
		} else if(strcmp(extension, ".txt") == 0) {
			createPath(currentElement->d_name, "Data/", extension, path);
			fprintf(log, "OPPENING FILE : %s \t ", path);
			if(!getIdInDescriptorBase(descriptorBasePictures, id, path)) {
				currentPicture = fopen(path, "r");
				if(openPict(currentPicture, log, descriptorBasePictures, path) == -1) {
					fprintf(log, " : WRITING IMAGE DATA FAIL ! \n");
					continue;
				}
				fprintf(log, "FILE INDEXED ! \n");
				fclose(currentPicture);
			} else {
				ret = getIfFileHasModified(id, path, log, "image");
				if(ret == 1) {
					fprintf(log, "FILE ALLREADY INDEXED ! \n");
				} else if(ret == -1){
					fprintf(log, "READ DESCRIPTOR FAIL ! \n");
				} else {
					memset(buffer, 0, BUFFER_SIZE);
					sprintf(buffer, "%s\t%s\n", path, id);
					supprDescriptorHeader(descriptorBasePictures, buffer, "image");
					supprDescriptor(id, "image");
					currentPicture = fopen(path, "r");
					if(openPict(currentPicture, log, descriptorBasePictures, path) == -1) {
						fprintf(log, " : WRITING IMAGE DATA FAIL ! \n");
						continue;
					}
					fclose(currentPicture);
					fprintf(log, "FILE HAS BEEN MODIFIED ! \n");
				}
			}
		/**
		 * Fichier Textes
		 */
		} else if(strcmp(extension, ".xml") == 0) {
			createPath(currentElement->d_name, "Data/", extension, path);
			fprintf(log, "OPPENING FILE : %s \t ", path);
			if(!getIdInDescriptorBase(descriptorBaseTexts, id, path)) {
				currentText = fopen(path, "r");
				if(get_words(currentText, log, descriptorBaseTexts, path) == -1) {
					fprintf(log, " : WRITING TEXT DATA FAIL ! \n");
					continue;
				}
				fprintf(log, "FILE INDEXED ! \n");
				fclose(currentText);
			} else {
				ret = getIfFileHasModified(id, path, log, "text");
				if(ret == 1) {
					fprintf(log, "FILE ALLREADY INDEXED ! \n");
				} else if(ret == -1){
					fprintf(log, "READ DESCRIPTOR FAIL ! \n");
				} else {
					memset(buffer, 0, BUFFER_SIZE);
					sprintf(buffer, "%s\t%s\n", path, id);
					supprDescriptorHeader(descriptorBaseTexts, buffer, "text");
					supprDescriptor(id, "text");
					currentText = fopen(path, "r");
					if(get_words(currentText, log, descriptorBaseTexts, path) == -1) {
						fprintf(log, " : WRITING TEXT DATA FAIL ! \n");
						continue;
					}
					fclose(currentText);
					fprintf(log, "FILE HAS BEEN MODIFIED ! \n");
				}
			}
			continue;
		}
		memset(path, 0, BUFFER_SIZE);
	}

	/**
	 * Fermer le dossier et rentree a la maison
	 */
	closedir(data);
	fclose(descriptorBaseSound);
	fclose(descriptorBasePictures);
	fclose(descriptorBaseTexts);
	fclose(log);
	printf("DONE ! \n");
	return(EXIT_SUCCESS);
}