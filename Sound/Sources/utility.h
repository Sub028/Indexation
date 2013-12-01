#ifndef UTILITY_H
#define UTILITY_H

#define true 1
#define false 0

typedef int Boolean;

void extractName(char fullName[100], char *nameOnly);
void createPath(char fullName[100], char prefix[100], char suffix[100], char *fileName);

#endif /*UTILITY_H*/