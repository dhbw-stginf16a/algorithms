#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"
#include "arrays.h"
#include "mergesort.h"

#define D_LT(x, y) ((x) < (y) && ++MERGE_DATA_COMPS)
#define D_GT(x, y) ((x) > (y) && ++MERGE_DATA_COMPS)
int MERGE_DATA_COMPS = 0;

#define I_LT(x, y) ((x) < (y) && ++MERGE_INDEX_COMPS)
#define I_GT(x, y) ((x) > (y) && ++MERGE_INDEX_COMPS)
int MERGE_INDEX_COMPS = 0;

int MERGE_ACCESSES = 0;
int m_access(int *array, int i) {
    MERGE_ACCESSES++;
    return array[i];
}

void recursiveMergesort(int a[], int len) {
    int *aux = (int *) malloc(len * sizeof(int)); // allocate aux array
    sort(a, 0, len - 1, aux);
}

void sort(int a[], int low, int high, int aux[]) {
    int mid;
    if (I_GT(high, low)) {
        mid = (high + low) / 2;
        sort(a, low, mid, aux);     // left
        sort(a, mid+1, high, aux);  // right
        merge(a, low, mid, high, aux);
    }
}

void merge(int a[], int low, int mid, int high, int aux[]) {
    int i = low;
    int j = mid + 1;
    int k;

    for (k = low; k <= high; k++)  // Copy a[low..high] to aux[low..high].
        aux[k] = m_access(a, k);
    for (k = low; k <= high; k++) {  // Merge back to a[low..high].
        if (I_GT(i, mid))  // end of 1st half
            a[k] = m_access(aux, j++); // rest of 2nd half
        else if (I_GT(j, high))  // end of 2nd half
            a[k] = m_access(aux, i++); // rest of 1st half
        else if (D_LT(m_access(aux, j), m_access(aux, i))) // compare values
            a[k] = m_access(aux, j++);
        else
            a[k] = m_access(aux, i++);
    }
}
