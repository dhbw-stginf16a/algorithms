#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "lib/array.h"
#include "sorting/mergesort.h"
#include "sorting/quicksort.h"

#define SIZE 160000
int index_comps = 0;
int value_comps = 0;
int array_accesses = 0;

void evaluate_sort(void (*sort)(int*, int), char *name, int decreasing){
    int *arr;

    if (decreasing) {
        arr = getDecreasingArray(SIZE);
    } else {
        arr = getUnsortedArray(SIZE);
    }

    index_comps = 0;
    value_comps = 0;
    array_accesses = 0;
    clock_t begin = clock();
    (*sort)(arr, SIZE);
    clock_t end = clock();

    char *title;
    if (decreasing) {
        title = malloc(strlen(name) + strlen("decreasing"));
        sprintf(title, "%s decreasing", name);
    } else {
        title = malloc(strlen(name) + strlen("random"));
        sprintf(title, "%s random", name);
    }
    printf("| %-30s | %11s |\n", title, "Measurement");
    printf("|--------------------------------+-------------|\n");
    printf("| %-30s | %9.0fms |\n", "Time", (double)((end - begin)*1000/CLOCKS_PER_SEC));
    printf("| %-30s | %11d |\n", "Index comparisons", index_comps);
    printf("| %-30s | %11d |\n", "Value comparisons", value_comps);
    printf("| %-30s | %11d |\n", "Array accesses", array_accesses);
    printf("\n");
}

void main () {
    clock_t begin;
    clock_t end;
    int *unsorted;

    // quicksort
    evaluate_sort(first_quicksort, "QUICKSORT: first,", 1);
    evaluate_sort(first_quicksort, "QUICKSORT: first,", 0);
    evaluate_sort(median_quicksort, "QUICKSORT: median,", 1);
    evaluate_sort(median_quicksort, "QUICKSORT: median,", 0);
    evaluate_sort(recursive_mergesort, "MERGESORT:", 1);
    evaluate_sort(recursive_mergesort, "MERGESORT:", 0);

}