#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include "Sound/wavFile.h"

int main(int argc, char *argv[]) {
	struct dirent *currentElement;
	DIR *folder;
	WavFile wavFile;
	char extension[BUFFER_SIZE] = {0};
	char buffer[BUFFER_SIZE] = {0};
	char path[BUFFER_SIZE] = {0};
	char id[BUFFER_SIZE] = {0};
	FILE *descriptorBase;
	FILE *log;
	int ret;
	time_t aclock;

	time(&aclock);
	folder = opendir("Data/");
	descriptorBase = fopen("Bases/liste_base_audio.base", "a+");
	if(descriptorBase == NULL) {
		system("mkdir Bases");
		descriptorBase = fopen("Bases/liste_base_audio.base", "a+");
	}
	log = fopen("log.log", "a");
	if(folder == NULL) {
		perror("Probleme lors de l'ouverture du dossier ");
		return(EXIT_FAILURE);
	}
	fprintf(log, "%s", ctime(&aclock));
	checkDescriptorBase(descriptorBase, log);
	while((currentElement = readdir(folder))) {
		extractExtension(currentElement->d_name, extension);
		if(strcmp(extension, ".wav") == 0) {
			createPath(currentElement->d_name, "Data/", extension, path);
			fprintf(log, "OPPENING FILE : %s \t ", path);
			if(!getIdInDescriptorBase(descriptorBase, id, path)) {
				openWavFile(&wavFile, path);
				if(writeDescriptor(&wavFile, descriptorBase, log) == -1) {
					fprintf(log, " : WRITING DATA FAIL ! \n");
					continue;
				}
				closeWavFile(&wavFile);
			} else {
				ret = getIfFileHasModified(id, path, log);
				if(ret == 1) {
					fprintf(log, "FILE ALLREADY INDEXED ! \n");
				} else if(ret == -1){
					fprintf(log, "READ DESCRIPTOR FAIL ! \n");
				} else {
					memset(buffer, 0, BUFFER_SIZE);
					sprintf(buffer, "%s\t%s\n", path, id);
					supprDescriptorHeader(descriptorBase, buffer);
					supprDescriptor(id);
					openWavFile(&wavFile, path);
					if(writeDescriptor(&wavFile, descriptorBase, log) == -1) {
						fprintf(log, " : WRITING DATA FAIL ! \n");
						continue;
					}
					closeWavFile(&wavFile);
					fprintf(log, "FILE HAS BEEN MODIFIED ! \n");
				}
				continue;
			}
			fprintf(log, "FILE INDEXED ! \n");
		}
	}

	/**
	 * Fermer le dossier et rentree a la maison
	 */
	printf("DONE ! \n");
	closedir(folder);
	fclose(descriptorBase);
	fclose(log);
	return(EXIT_SUCCESS);
}