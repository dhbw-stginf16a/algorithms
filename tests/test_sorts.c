#include "../Unity/src/unity.h"

#include "../lib/shuffle.h"
#include "../lib/array.h"

#include "../sorting/insertionsort.h"
#include "../sorting/bubblesort.h"
#include "../sorting/quicksort.h"
#include "../sorting/mergesort.h"
#include "../sorting/heapsort.h"

#define SIZE 100

void test_sort(void (*sort)(int*, int)) {
    int *ordered = getIncreasingArray(SIZE);
    int *unordered = getIncreasingArray(SIZE);
    shuffle(unordered, SIZE);
    (*sort)(unordered, SIZE);
    TEST_ASSERT_EQUAL_INT_ARRAY(ordered, unordered, SIZE);
}

void test_bubblesort(void) {
    test_sort(&bubblesort);
}

void test_flagged_bubblesort(void) {
    test_sort(&flagged_bubblesort);
}
void test_shuttlesort(void) {
    test_sort(&shuttlesort);
}

void test_insertionsort(void) {
    test_sort(&insertionsort);
}

void test_median_quicksort(void) {
    test_sort(&median_quicksort);
}

void test_first_quicksort(void) {
    test_sort(&first_quicksort);
}

void test_natural_mergesort(void) {
    test_sort(&natural_mergesort);
}

void test_recursive_mergesort(void) {
    test_sort(&recursive_mergesort);
}

void test_heapsort(void) {
	test_sort(&heapSort);
}
