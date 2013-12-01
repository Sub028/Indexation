#ifndef WAV_HEADER_H
#define WAV_HEADER_H

/**
 * @see https://ccrma.stanford.edu/courses/422/projects/WaveFormat/
 */
typedef struct WavHeader {
	//The "RIFF" chunk descriptor
	char chunkId[4];
	int chunkSize;
	char format[4];

	//The "fmt" sub-chunk descriptor
	char subChunk1Id[4];
	int subChunk1Size;
	short audioFormat;
	short numChannels;
	int sampleRate;
	int byteRate;
	short blockAlign;
	short bitsPerSample;

	//The "data" sub-chunk descriptor
	char subChunk2Id[4];
	int subChunk2Size;
} WavHeader;

void initWavHeader(WavHeader *wavHeader);
void writeHeader(WavHeader *wavHeader, FILE *file);
int writeWavHeader(WavHeader *wavHeader, FILE *file);
int readHeader(WavHeader *wavHeader, FILE *file);

#endif /*WAV_HEADER_H*/