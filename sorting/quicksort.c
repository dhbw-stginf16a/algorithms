#include "../lib/array.h"
#include "../lib/shuffle.h"

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
        // choose the median as pivot
        if (medianPivot) {
            int len = from - to;
            swap(a, from, getMedian(a, from, (from + to) / 2, to));
        }
        pivot = from;
        for (i = from + 1; i <= to; i++) {
            new_val = a[i];
            if (new_val < a[pivot]) {
                a[i] = a[pivot+1];
                a[pivot+1] = a[pivot];
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
    if (array[a] < array[c]) {
        if (array[b] > array[c]) {
            return c;
        } else if (array[b] < array[a]) {
            return a;
        } else {
            return b;
        }
    } else {
        if (array[b] < array[c]) {
            return b;
        } else if (array[b] > array[a]) {
            return a;
        } else {
            return b;
        }
    }
}
