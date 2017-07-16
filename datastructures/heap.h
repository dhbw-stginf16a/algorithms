#include <stddef.h>

typedef struct Heap {
	int* heapArr;
	size_t size;
	int lastElem;
} Heap;

Heap* createHeap(size_t size);
void insertInHeap(Heap* heapToInsert, int value);
int maximumValue(Heap* heap);
void deleteMaximumElem(Heap* heap);
void destroyHeap(Heap* heap);
void printHeapArray(Heap* heap);
