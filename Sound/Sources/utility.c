#include <string.h>
#include "utility.h"

int indexOfNameBegin(char fullName[100]) {
	int i;
	int index = 0;

	for(i = 0; i < 100, fullName[i] != '\0'; i++) {
		if(fullName[i] == '/') {
			index = i + 1;
		}
	}
	return(index);
}

void extractName(char fullName[100], char *nameOnly) {
	char name[100] = {0};
	int i, j;
	int begin = indexOfNameBegin(fullName);

	for(i = begin, j = 0; i < 100; i++, j++) {
		if(fullName[i] == '.') {
			break;
		}
		name[j] = fullName[i];
	}
	strcpy(nameOnly, name);
}

void createPath(char fullName[100], char prefix[100], char suffix[100], char *fileName) {
	char buffer[100] = {0};
	char nameOnly[100];

	extractName(fullName, nameOnly);
	strcpy(buffer, prefix);
	strcat(buffer, nameOnly);
	strcat(buffer, suffix);
	strcpy(fileName, buffer);
}