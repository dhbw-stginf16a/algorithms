#include "../Unity/src/unity.c"

#include "test_sorts.h"
#include "test_fibonacci.h"
#include "test_factorial.h"

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_insertionsort);

    RUN_TEST(test_bubblesort);
    RUN_TEST(test_flagged_bubblesort);
    RUN_TEST(test_shuttlesort);

    RUN_TEST(test_median_quicksort);
    RUN_TEST(test_first_quicksort);

    RUN_TEST(test_natural_mergesort);
    RUN_TEST(test_recursive_mergesort);

    RUN_TEST(test_fib_recursive);
    RUN_TEST(test_fib_iterative);

    RUN_TEST(test_fact);

    return UNITY_END();
}
