//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: ERDELYI Jean-François
// Date de création: 01/12/13
//======================================================================//
// Fichier C: utility.c ou Fichier H: utility.h
//======================================================================//
// Module UTILITY (ALL):
// - Permet de faire diverse manipulation utile pour le projets.
//======================================================================//

/**
 * \file utility.c
 * \author Jean-François Erdelyi
 * \brief Permet de faire diverse manipulation utile pour le projets.
 * \version 1
 * \date 01 decembre 2013.
 * 
 * Permet de faire diverse manipulation utile pour le projets.
 * 
 */

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "utility.h"

/**
 * \fn int indexOfNameBegin(char *fullName])
 * \brief Retourne a partir d'ou le nom de fichier commence.
 *
 * \param fullName Le chemin complet du fichier.
 * \return L'indice d'ou le nom de fichier commence.
 */
int indexOfNameBegin(char *fullName) {
	int i;
	int index = 0;

	for(i = 0; i < BUFFER_SIZE, fullName[i] != '\0'; i++) {
		if(fullName[i] == '/') {
			index = i + 1;
		}
	}
	return(index);
}

/**
 * \fn void getStringUntil(char *input, char *output, char c)
 * \brief Récupére une sous chaine jusqu'au délimitateur.
 *
 * \param input Chaine en entrée.
 * \param output Chaine en sortie.
 * \param c Caractère d'arrêt.
 */
void getStringUntil(char *input, char *output, char c) {
	int i;
	for(i = 0; i < BUFFER_SIZE; i++) {
		if(input[i] == c) {
			break;
		}
		output[i] = input[i];
	}
}

/**
 * \fn void splitHeaderJustSize(char *header, int *nbBars, int *nbWindows)
 * \brief Permet d'extraire juste la taille de la matrice (descripteur audio).
 *
 * \param header Le header d'un descripteur.
 * \param nbBars Le nombre de barres en sorties.
 * \param nbWindows Le nombre de fenétres en sorties.
 */
void splitHeaderJustSize(char *header, int *nbBars, int *nbWindows) {
	sscanf(header, "%*s\t%d\t%d", nbBars, nbWindows);
}

/**
 * \fn void splitHeader(char *header, char *id, int *nbBars, int *nbWindows, char *date)
 * \brief Permet d'extraire toutes les composante d'un header audio
 *
 * \param header Le header d'un descripteur.
 * \param id L'ID du descripteur.
 * \param nbBars Le nombre de barres en sorties.
 * \param nbWindows Le nombre de fenétres en sorties.
 * \param date La date de dernière modification du fichier.
 */
void splitHeader(char *header, char *id, int *nbBars, int *nbWindows, char *date) {
	char buffer[5][BUFFER_SIZE] = {0};
	sscanf(header, "%s\t%d\t%d\t%s%s%s%s%s", id, nbBars, nbWindows, buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
	sprintf(date, "%s %s %s %s %s\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
}

/**
 * \fn void splitDate(char *dateIn, char *dateOut)
 * \brief Permet de formaté la date pour la comparé.
 *
 * \param dateIn Date en entrée.
 * \param dateOut Date en sortie.
 */
void splitDate(char *dateIn, char *dateOut) {
	char buffer[5][BUFFER_SIZE] = {0};
	sscanf(dateIn, "%s%s%s%s%s", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
	sprintf(dateOut, "%s %s %s %s %s\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
}

/**
 * \fn void extractName(char *fullName, char *nameOnly)
 * \brief Retourne la cellule correspondant a la clef.
 *
 * \param fullNameLe Le chemin complet du fichier.
 * \param nameOnly Le nom brut.
 */
void extractName(char *fullName, char *nameOnly) {
	char name[BUFFER_SIZE] = {0};
	int i, j;
	int begin = indexOfNameBegin(fullName);

	for(i = begin, j = 0; i < BUFFER_SIZE; i++, j++) {
		if(fullName[i] == '.') {
			break;
		}
		name[j] = fullName[i];
	}
	strcpy(nameOnly, name);
}

/**
 * \fn void extractExtension(char *fullName, char *extension)
 * \brief Retourne la cellule correspondant a la clef.
 *
 * \param fullNameLe Le chemin complet du fichier.
 * \param extension L'extension.
 */
void extractExtension(char *fullName, char *extension) {
	char name[BUFFER_SIZE] = {0};
	int i, j;
	int begin = indexOfNameBegin(fullName);

	for(i = begin; i < BUFFER_SIZE; i++) {
		if(fullName[i] == '.') {
			break; 
		}
	}
	begin = i;
	for(j = begin, i = 0; j < BUFFER_SIZE && fullName[i] != '\0'; j++, i++) {
		name[i] = fullName[j];
	}
		
	strcpy(extension, name);
}

/**
 * \fn void createPath(char *fullName, char *prefix, char *suffix, char *fileName)
 * \brief Crée un nouveau chemin pour un fichier.
 *
 * \param fullName Le chemin complet du fichier.
 * \param prefix Ce qui va etre avant le nom du fichier.
 * \param suffix Ce qui va etre apres le nom du fichier.
 * \param fileName Le nouveau chemin.
 * 
 * Exemple : 
 * fullName = Data/Test.wav
 * prefix = Results/
 * suffix = _resultat.wav
 * le nouveau chemin sera :
 * fileName = Results/Test_resultat.wav
 */
void createPath(char *fullName, char *prefix, char *suffix, char *fileName) {
	char buffer[BUFFER_SIZE] = {0};
	char nameOnly[BUFFER_SIZE];

	extractName(fullName, nameOnly);
	strcpy(buffer, prefix);
	strcat(buffer, nameOnly);
	strcat(buffer, suffix);
	strcpy(fileName, buffer);
}

/**
 * \fn int supprDescriptor(char *id)
 * \brief Supprime un descripteur.
 *
 * \param id L'ID du descripteur.
 * \return -1 si problème sur l'ouverture des fichiers 0 sinon
 */
int supprDescriptor(char *id) {
	char buffer[BUFFER_SIZE];
	char curentID[BUFFER_SIZE];
	FILE *bufferFile;
	FILE *base;
	int i = 0;
	int nbBars;
	int nbWindows;

	if((bufferFile = fopen("Bases/base_descripteur_audio.base.tmp", "w")) == NULL) {
		return(-1);
	}
	if((base = fopen("Bases/base_descripteur_audio.base", "r")) == NULL) {
		return(-1);
	}

	while(fgets(buffer, BUFFER_SIZE, base)) {
		if(buffer[0] != 'I') {
			fputs(buffer, bufferFile);
			memset(buffer, 0, BUFFER_SIZE);
			continue;
		}
		getStringUntil(buffer, curentID, '\t');
		if(strcmp(curentID, id) != 0) {
			fputs(buffer, bufferFile);
		} else {
			splitHeaderJustSize(buffer, &nbBars, &nbWindows);
			for(i = 0; i < nbWindows; i++) {
				fgets(buffer, BUFFER_SIZE, base);
			}
		}
		memset(buffer, 0, BUFFER_SIZE);
	}
	fclose(bufferFile);
	fclose(base);
	rename("Bases/base_descripteur_audio.base.tmp", "Bases/base_descripteur_audio.base");
	return(0);
}

/**
 * \fn int supprDescriptorHeader(FILE *base, char *line)
 * \brief Supprime une association fichier/ID.
 *
 * \param base Base des descripteur.
 * \param line Ligne a supprimer.
 * \return -1 si problème sur l'ouverture des fichiers 0 sinon
 */
int supprDescriptorHeader(FILE *base, char *line) {
	char buffer[BUFFER_SIZE];
	FILE *bufferFile;
	int i = 0;

	rewind(base);
	if((bufferFile = fopen("Bases/liste_base_audio.base.tmp", "w")) == NULL) {
		return(-1);
	}
	while(fgets(buffer, BUFFER_SIZE, base)) {
		if(strcmp(buffer, line) != 0) {
			fputs(buffer, bufferFile);
		}
	}
	fclose(bufferFile);
	fclose(base);
	rename("Bases/liste_base_audio.base.tmp", "Bases/liste_base_audio.base");
	base = fopen("Bases/liste_base_audio.base", "a+");
	return(0);
}

/**
 * \fn void checkDescriptorBase(FILE *base
 * \brief Permet de controler si les base ne contienne pas de fichier supprimé
 *
 * \param fullName Le chemin complet du fichier.
 */
void checkDescriptorBase(FILE *base, FILE *log) {
	char currentId[BUFFER_SIZE] = {0};
	char currentFileName[BUFFER_SIZE] = {0};
	char buffer[BUFFER_SIZE] = {0};
	int find  = 0;
	FILE *file;

	while(!feof(base)){
		fscanf(base, "%s\t%s\n", currentFileName, currentId);
		if(strcmp(currentFileName, "") == 0) {
			continue;
		}
		file = fopen(currentFileName, "r");
		if(file == NULL) {
			fprintf(log, "CHECK DATABASE : %s \t DELETED OF BASE ! \n", currentFileName);
			sprintf(buffer, "%s\t%s\n", currentFileName, currentId);
			supprDescriptorHeader(base, buffer);
			supprDescriptor(currentId); 
			continue;
		}
		fclose(file);
	}
}


/**
 * \fn int getIdInDescriptorBase(FILE *base, char *id, char *fileName)
 * \brief Permet de récuperer l'ID d'un fichier déjà indexer.
 *
 * \param base La base des descripeur.
 * \param id L'id associer au fichier.
 * \param fileName Le nouveau chemin.
 * \return 1 pour trouver ou 0.
 */
int getIdInDescriptorBase(FILE *base, char *id, char *fileName) {
	char buffer[BUFFER_SIZE] = {0};
	char currentId[BUFFER_SIZE] = {0};
	char currentFileName[BUFFER_SIZE] = {0};
	int find  = 0;

	rewind(base);
	do {
		fscanf(base, "%s\t%s\n", currentFileName, currentId);
		if(strcmp(currentFileName, fileName) == 0) {
			strcpy(id, currentId);
			find = 1;
		}
	} while(!feof(base) && !find);
	fseek(base, 0, SEEK_END);

	return(find);
}

/**
 * \fn int getNameAndValue(char *word, char *name, int *value)
 * \brief Permet de récuperer le nom et sa valeur associer.
 * 
 * \param line Ligne du fichier de configuration.
 * \param name Nom de la clef.
 * \param value Valeur de la clef.
 * \return -1 si la ligne est vide.
 * 
 * Permet pour une ligne du fichier de configuration de récuperer le couple
 * nom, valeur si la fonction retourn -1 il y a rien a récuperer.
 * N'est pas proposer a l'utilisateur, il utilisera plutot "readConfigLine".
 */
int getKeyAndValue(char *line, char *key, int *value) {
	char nameBuffer[BUFFER_SIZE] = {0};
	char valueBuffer[BUFFER_SIZE] = {0};
	int i, j;
	
	if(line == NULL) {
		return(-1);
	}

	for(i = 0; line[i] != '=' && i != BUFFER_SIZE; i++) {
		nameBuffer[i] = line[i];
	}
	nameBuffer[i++] = '\0';
	for(j = 0; line[i] != '\n' && i != BUFFER_SIZE; i++, j++) {
		valueBuffer[j] = line[i];
	}

	valueBuffer[j] = '\0';
	*value = atoi(valueBuffer);
	strcpy(key, nameBuffer);
	return(0);
}

/**
 * \fn int getNameAndValue(char *name, int *value)
 * \brief Permet de récuperer le nom et sa valeur associer.
 * 
 * \param name Nom de la clef auquel on cherche sa valeur.
 * \param value Valeur de la clef.
 * \return -1 les information sont vide, ou non trouver.
 * 
 * Permet pour une ligne du fichier de configuration de récuperer le couple
 * nom, valeur si la fonction retourn -1 il y a rien a récuperer.
 */
int getValueOf(char *key, int *value) {
	FILE *configFile = fopen("config.conf", "r");
	char buffer[BUFFER_SIZE];
	char currentKey[BUFFER_SIZE];
	int currentValue;
	int ret = -1;

	if(configFile == NULL) {
		fclose(configFile);
		return(-1);
	}

	do {
		fgets(buffer, BUFFER_SIZE, configFile);	
		if(getKeyAndValue(buffer, currentKey, &currentValue) == -1) {
			ret = -1;
			break;
		}	
		if(strcmp(currentKey, key) == 0) {
			ret = 0;
			*value = currentValue;
			break;
		}
	} while(!feof(configFile));

	fclose(configFile);
	return(ret);
}

/**
 * \fn int getIfFileHasModified(char *id, char *header, char *fileName, FILE *log)
 * \brief Permet de savoir si le fichier courant a été modifier.
 * 
 * \param id Identifiant du descripteur.
 * \param fileName Chemin du fichier.
 * \param log Fichier de log.
 * \return -1 les information sont vide, ou ficheir non trouver.
 */
int getIfFileHasModified(char *id, char *fileName, FILE *log) {
	char buffer[BUFFER_SIZE] = {0};
	char header[BUFFER_SIZE] = {0};
	char currentID[BUFFER_SIZE] = {0};
	char date[BUFFER_SIZE] = {0};
	char fileDate[BUFFER_SIZE] = {0};
	char headerID[BUFFER_SIZE] = {0};
	FILE *soundBase = fopen("Bases/base_descripteur_audio.base", "r");
	int nbBars;
	int nbWindows;
	struct stat st;

	if(stat(fileName, &st) == -1) {
		fprintf(log, "STAT ERROR ");
		return(-1);
	}
	while(!feof(soundBase)) {
		fgets(buffer, BUFFER_SIZE, soundBase);
		if(buffer[0] != 'I') {
			continue;
		}
		getStringUntil(buffer, currentID, '\t');
		if(strcmp(currentID, id) == 0) {
			strcpy(header, buffer);
			splitHeader(header, headerID, &nbBars, &nbWindows, date);
			splitDate(ctime(&st.st_mtime), fileDate);
			if(strcmp(date, fileDate) == 0) {
				fclose(soundBase);
				return(1);
			} else {
				return(0);
			}
			
		}
		memset(currentID, 0, BUFFER_SIZE);
	}
	fclose(soundBase);
	return(-1);
}
