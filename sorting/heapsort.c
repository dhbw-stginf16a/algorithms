#include <stdio.h>

#include "../datastructures/heap.h"
#include "heapsort.h"

void heapSort(int arr[], int len)
{
	int i;
	Heap* heapToSort = createHeap(len);
	for (i = 0; i < len; i++)
	{
		insertInHeap(heapToSort, arr[i]);
	}

	for (i = len - 1; i >= 0; i--)
	{	
		arr[i] = maximumValue(heapToSort);
		deleteMaximumElem(heapToSort);
	}

	destroyHeap(heapToSort);
}
