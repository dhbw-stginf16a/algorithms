#include <stdlib.h>
#include <stdio.h>

#include "heap.h"
#include "../lib/array.h"

//needed for inserting
void sortUpwards(Heap* heap, int currentIndex)
{
	if (!heap || currentIndex <= 1 || currentIndex > heap->size)
	{
		return;
	}
	
	//sort the element upwards inside the tree if next element is smaller
	if (heap->heapArr[currentIndex / 2] < heap->heapArr[currentIndex])
	{
		swap(heap->heapArr, currentIndex, currentIndex / 2);
		sortUpwards(heap, currentIndex / 2);
	}
}

//needed for deleting
void sortDownwards(Heap* heap, int currentIndex)
{
	if (currentIndex * 2 > heap->lastElem)
	{
		return;
	}

	if ((heap->heapArr[currentIndex] < heap->heapArr[currentIndex * 2]) && (heap->heapArr[currentIndex * 2] >= heap->heapArr[currentIndex * 2 + 1]))
	{
		swap(heap->heapArr, currentIndex, currentIndex * 2);
		sortDownwards(heap, currentIndex * 2);
	}
	else if (heap->heapArr[currentIndex] < heap->heapArr[currentIndex * 2 + 1])
	{
		swap(heap->heapArr, currentIndex, currentIndex * 2 + 1);
		sortDownwards(heap, currentIndex * 2 + 1);
	}
}


//initializes new heap, allocates memory
Heap* createHeap(size_t size)
{
	Heap* temp = malloc(sizeof(Heap));
	temp->heapArr = calloc(size + 1, sizeof(int));
	temp->lastElem = 0;
	temp->size = size;
	
}

//inserts element into heap by inserting as new last element and sorting it upwards
void insertInHeap(Heap* heapToInsert, int value)
{
	if (heapToInsert->lastElem >= (int) heapToInsert->size)
	{
		return;
	}

	heapToInsert->heapArr[++heapToInsert->lastElem] = value;
	sortUpwards(heapToInsert, heapToInsert->lastElem);
}

//in a heap, the maximum is always the root node
int maximumValue(Heap* heap)
{
	return heap->heapArr[1];
}

void deleteMaximumElem(Heap* heap)
{
	if (heap->lastElem < 1)
	{
		return;
	}
	//move last element to top and sort it down
	heap->heapArr[1] = heap->heapArr[heap->lastElem];
	--heap->lastElem;
	sortDownwards(heap, 1);
}

void destroyHeap(Heap* heap)
{
	free(heap->heapArr);
	free(heap);
}

void printHeapArray(Heap* heap)
{
	int i;
	printf("HEAP: ");
	for (i = 1; i <= heap->lastElem; i++)
	{
		printf("%d ", heap->heapArr[i]);
	}
	printf("\n");
}
