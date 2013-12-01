#ifndef HISTOGRAM_H
#define HISTOGRAM_H

typedef struct HistogramCell {
	int value;
	int occurence;
	struct HistogramCell *nextCell;
} HistogramCell;

typedef struct Histogram {
	HistogramCell *begin;
	HistogramCell *end;
} Histogram;

void initHistogram(Histogram *histo, int nbValues);
void addValue(Histogram *histo, int value);
HistogramCell* getHistogramCell(Histogram *histo, int value);
void freeHistogram(Histogram *histo);

#endif /*HISTOGRAM_H*/