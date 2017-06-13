#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"
#include "arrays.h"

// Compare data Less Than and Greater Than
#define D_LT(x, y) ((x) < (y) && ++DATA_COMPS)
#define D_GT(x, y) ((x) > (y) && ++DATA_COMPS)
int DATA_COMPS = 0;

// Compare indices Less Than and Greater Than
#define I_LT(x, y) ((x) < (y) && ++INDEX_COMPS)
#define I_GT(x, y) ((x) > (y) && ++INDEX_COMPS)
int INDEX_COMPS = 0;

// Count array accesses
int ACCESSES = 0;
int access(int *array, int i) {
    ACCESSES++;
    return array[i];
}

/**
 * Qucksort with median of first, middle and last element as pivot
 */
void medianQuicksort(int a[], int len) {
    lenQuicksort(a, len, 1);
}

/**
 * Quicksort with first element as pivot.
 */
void firstQuicksort(int a[], int len) {
    shuffle(a, len);
    lenQuicksort(a, len, 0);
}

/**
 * Quicksort.
 *
 * @param int a[]         array to be sorted
 * @param int len         length of the array
 * @param int medianPivot median as pivot? (bool)
 */
void lenQuicksort(int a[], int len, int medianPivot) {
    quicksort(a, 0, len - 1, medianPivot);
}

/**
 * Quicksort.
 *
 * @param int a[]         array to be sorted
 * @param int start       start point of the array
 * @param int end         end point of the array
 * @param int medianPivot median as pivot? (bool)
 */
void quicksort(int a[], int from, int to, int medianPivot) {
    int i, new_val, pivot;

    if (I_LT(from, to)) {
        // choose the median as pivot
        if (medianPivot) {
            int len = from - to;
            swap(a, from, getMedian(a, from, (from + to) / 2, to));
        }
        pivot = from;
        for (i = from + 1; i <= to; i++) {
            new_val = access(a, i);
            if (D_LT(new_val, access(a, pivot))) {
                a[i] = access(a, pivot+1);
                a[pivot+1] = access(a, pivot);
                a[pivot] = new_val;
                pivot++;
            }
        }
        quicksort(a, from, pivot - 1, medianPivot);  // left partition
        quicksort(a, pivot + 1, to, medianPivot);    // right partition
    }
}

/**
 * Get the index with the median value of those three.
 * @param int array[] array in which the values are
 * @param int a       first index in the array
 * @param int b       second index in the array
 * @param int c       third index in the array
 */
int getMedian(int array[], int a, int b, int c) {
    if (D_LT(access(array, a), access(array, c))) {
        if (D_GT(access(array, b), access(array, c))) {
            return c;
        } else if (D_LT(access(array, b), access(array, a))) {
            return a;
        } else {
            return b;
        }
    } else {
        if (D_LT(access(array, b), access(array, c))) {
            return b;
        } else if (D_GT(access(array, b), access(array, a))) {
            return a;
        } else {
            return b;
        }
    }
}
