#include <stdio.h>
#include <stdlib.h>

#include "array.h"
#include "shuffle.h"

/**
 * Swap elements of a at indices left and right.
 */
void swap(int a[], int left, int right) {
    int left_value = a[left];
    a[left] = a[right];
    a[right] = left_value;
}

/**
 * Get an increasing array of integers with specific length.
 */
int *getIncreasingArray(int len) {
    int *array = (int*) malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        array[i] = i;
    }
    return array;
}

/**
 * Get an decreasing array of integers with specific length.
 */
int *getDecreasingArray(int len) {
    int *array = (int*) malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        array[i] = len - i - 1;
    }
    return array;
}

/**
 * Get an unsorted array of length len
 */
int *getUnsortedArray(int len) {
    int *array = getIncreasingArray(len);
     shuffle(array, len);
     return array;
}

/**
 * Print all elements of the array.
 */
void printArray(int a[], int len) {
    printSubArray(a, 0, len);
}

/**
 * Print all elements of the array inside bounds.
 */
void printSubArray(int a[], int begin, int end) {
    for (int i = begin; i < (end - begin); i++) {
        if (i != begin) {
            printf(", ");
        }
        printf("%3d", a[i]);
    }
    printf("\n");
}
