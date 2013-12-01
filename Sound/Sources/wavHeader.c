#include <stdio.h>
#include <string.h>
#include "wavHeader.h"

void initWavHeader(WavHeader *wavHeader) {
	memset(wavHeader, 0, sizeof(WavHeader));
}

void writeHeader(WavHeader *wavHeader, FILE *file) {
	//The "RIFF" chunk descriptor
	fprintf(file, "RIFF\t\t: %.4s\n", wavHeader->chunkId);
	fprintf(file, "Size\t\t: %d\n", wavHeader->chunkSize);
	fprintf(file, "Format\t\t: %.4s\n", wavHeader->format);

	//The "fmt" sub-chunk descriptor
	fprintf(file, "FMT\t\t: %.4s\n", wavHeader->subChunk1Id);
	fprintf(file, "FMT Chunk Size\t: %d\n", wavHeader->subChunk1Size);
	fprintf(file, "Format\t\t: %d\n", wavHeader->audioFormat);
	fprintf(file, "Channels\t: %d\n", wavHeader->numChannels);
	fprintf(file, "Sample Rate\t: %d\n", wavHeader->sampleRate);
	fprintf(file, "Byte Rate\t: %d\n", wavHeader->byteRate);
	fprintf(file, "Block Align\t: %d\n", wavHeader->blockAlign);
	fprintf(file, "Bits Per Sample\t: %d\n", wavHeader->bitsPerSample);

	//The "data" sub-chunk descriptor
	fprintf(file, "Data\t\t: %.4s\n", wavHeader->subChunk2Id);
	fprintf(file, "Data Chunk Size\t: %d\n", wavHeader->subChunk2Size);
}

int writeWavHeader(WavHeader *wavHeader, FILE *file) {
	return(fwrite(wavHeader, sizeof(WavHeader), 1, file));
}

int readHeader(WavHeader *wavHeader, FILE *file) {
	return(fread(wavHeader, sizeof(WavHeader), 1, file));
}
