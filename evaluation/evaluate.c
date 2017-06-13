#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "arrays.h"
#include "quicksort.h"
#include "mergesort.h"

void printStats(time_t time) {
    printf("| TIME        | %10d |\n", time);
    printf("| DATA_COMPS  | %10d |\n", DATA_COMPS);
    printf("| INDEX_COMPS | %10d |\n", INDEX_COMPS);
    printf("| ACCESSES    | %10d |\n", ACCESSES);
    DATA_COMPS = 0;
    INDEX_COMPS = 0;
    ACCESSES = 0;
}

void printMergeStats(time_t time) {
    printf("| TIME        | %10d |\n", time);
    printf("| DATA_COMPS  | %10d |\n", MERGE_DATA_COMPS);
    printf("| INDEX_COMPS | %10d |\n", MERGE_INDEX_COMPS);
    printf("| ACCESSES    | %10d |\n", MERGE_ACCESSES);
    MERGE_DATA_COMPS = 0;
    MERGE_INDEX_COMPS = 0;
    MERGE_ACCESSES = 0;
}

int main() {
    clock_t begin;
    clock_t end;
    double time_spent;
    // initialize random number generator
    srand(time(NULL));

    // generate array that is to be sorted
    int len = 16000;
    int *unsorted = getIncreasingArray(len);
    shuffle(unsorted, len);

    printf("1) Quicksort random: \n");
    printf("a) Descending values\n");
    unsorted = getDecreasingArray(len);
    begin = clock();
    firstQuicksort(unsorted, len);
    end = clock();
    printArray(unsorted, len);
    printStats(end - begin);
    printf("b) Random values\n");
    unsorted = getUnsortedArray(len);
    begin = clock();
    firstQuicksort(unsorted, len);
    end = clock();
    printArray(unsorted, len);
    printStats(end - begin);
    printf("\n");

    printf("2) Quicksort median: \n");
    printf("a) Descending values\n");
    unsorted = getDecreasingArray(len);
    printArray(unsorted, len);
    begin = clock();
    medianQuicksort(unsorted, len);
    end = clock();
    printArray(unsorted, len);
    printStats(end - begin);
    printf("b) Random values\n");
    unsorted = getUnsortedArray(len);
    printArray(unsorted, len);
    begin = clock();
    medianQuicksort(unsorted, len);
    end = clock();
    printArray(unsorted, len);
    printStats(end - begin);
    printf("b) Random values\n");
    unsorted = getUnsortedArray(len);
    printArray(unsorted, len);
    begin = clock();
    medianQuicksort(unsorted, len);
    end = clock();
    printArray(unsorted, len);
    printStats(end - begin);
    printf("\n");

    printf("3) Mergesort: \n");
    printf("a) Descending values\n");
    unsorted = getDecreasingArray(len);
    begin = clock();
    recursiveMergesort(unsorted, len);
    end = clock();
    printArray(unsorted, len);
    printMergeStats(end - begin);
    printf("b) Random values\n");
    unsorted = getUnsortedArray(len);
    begin = clock();
    recursiveMergesort(unsorted, len);
    end = clock();
    printArray(unsorted, len);
    printMergeStats(end - begin);

    return 0;
}
