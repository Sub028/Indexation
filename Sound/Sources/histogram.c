#include <stdio.h>
#include <stdlib.h>
#include "histogram.h"

void initHistogram(Histogram *histo, int nbValues) {
	int i;
	histo->begin = NULL;
	histo->end = NULL;
	for(i = 0; i < nbValues; i++) {
		addValue(histo, i + 1);
	}
}

void addValue(Histogram *histo, int value) {
	HistogramCell *currentCell = getHistogramCell(histo, value);
	if(currentCell != NULL) {
		currentCell->occurence++;
	} else {
		currentCell = (HistogramCell*)malloc(sizeof(HistogramCell));
		currentCell->occurence = 0;
		currentCell->value = value;
		currentCell->nextCell = NULL;
		if(isVoid(histo)) {
			histo->begin = currentCell;
			histo->end = histo->begin;
		} else {
			histo->end->nextCell = currentCell;
			histo->end = histo->end->nextCell;
		}
	}
}

int isVoid(Histogram *histo) {
	return(histo->begin == NULL);
}

HistogramCell* getHistogramCell(Histogram *histo, int value) {
	HistogramCell *currentCell = NULL;
	if(!isVoid(histo)) {
		currentCell = histo->begin;
		while(currentCell != NULL) {
			if(currentCell->value == value) {
				break;
			}
			currentCell = currentCell->nextCell;
		}
	}
	return(currentCell);
}

void writeHistogram(Histogram *histo, FILE *file) {
	HistogramCell *currentCell;
	if(!isVoid(histo)) {
		currentCell = histo->begin;
		while(currentCell != NULL) {
			fprintf(file, "%d", currentCell->occurence);
			currentCell = currentCell->nextCell;
			if(currentCell != NULL) {
				fprintf(file, "\t");
			}
		}
	}
}

void freeHistogram(Histogram *histo) {
	HistogramCell *currentCell = histo->begin;
	HistogramCell *nextCell;
	while(currentCell != NULL) {
		nextCell = currentCell->nextCell;
		free(currentCell);
		currentCell = nextCell;
	}
}