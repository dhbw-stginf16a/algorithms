#include "../lib/array.h"
#include "../lib/shuffle.h"

extern int index_comps;
extern int value_comps;
extern int array_accesses;

void len_quicksort(int a[], int len, int medianPivot);
void quicksort(int a[], int from, int to, int medianPivot);
int getMedian(int array[], int a, int b, int c);

/**
 * Qucksort with median of first, middle and last element as pivot
 */
void median_quicksort(int a[], int len) {
    len_quicksort(a, len, 1);
}

/**
 * Quicksort with first element as pivot.
 */
void first_quicksort(int a[], int len) {
    shuffle(a, len);
    len_quicksort(a, len, 0);
}

/**
 * Quicksort
 *
 * @param int a[]         array to be sorted
 * @param int len         length of the array
 * @param int medianPivot median as pivot? (bool)
 */
void len_quicksort(int a[], int len, int medianPivot) {
    quicksort(a, 0, len - 1, medianPivot);
}

/**
 * Quicksort on part of an array.
 *
 * @param int a[]         array to be sorted
 * @param int start       start point of the array
 * @param int end         end point of the array
 * @param int medianPivot median as pivot? (bool)
 */
void quicksort(int a[], int from, int to, int medianPivot) {
    int i, new_val, pivot;

    if (from < to) {
        index_comps++;
        // choose the median as pivot
        if (medianPivot) {
            int len = from - to;
            swap(a, from, getMedian(a, from, (from + to) / 2, to));
        }
        pivot = from;
        for (i = from + 1; i <= to; i++) {
            new_val = a[i];
            array_accesses++;
            if (new_val < a[pivot]) {
                array_accesses++;
                value_comps++;
                a[i] = a[pivot+1];
                array_accesses += 2;
                a[pivot+1] = a[pivot];
                array_accesses += 2;
                a[pivot] = new_val;
                array_accesses++;
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
    if (array[a] < array[c]) {
        array_accesses += 2;
        value_comps++;
        if (array[b] > array[c]) {
            array_accesses += 2;
            value_comps++;
            return c;
        } else if (array[b] < array[a]) {
            array_accesses += 4;
            value_comps += 2;
            return a;
        } else {
            array_accesses += 4;
            value_comps += 2;
            return b;
        }
    } else {
        array_accesses += 2;
        value_comps++;
        if (array[b] < array[c]) {
            array_accesses += 2;
            value_comps++;
            return b;
        } else if (array[b] > array[a]) {
            array_accesses += 4;
            value_comps += 2;
            return a;
        } else {
            array_accesses += 4;
            value_comps += 2;
            return b;
        }
    }
}
