#include "../Unity/src/unity.h"

#include "../maths/fibonacci.h"

void test_fib_recursive(void) {
    TEST_ASSERT_EQUAL_INT(1, fib_recursive(0));
    TEST_ASSERT_EQUAL_INT(1, fib_recursive(1));
    TEST_ASSERT_EQUAL_INT(2, fib_recursive(2));
}

void test_fib_iterative(void) {
    TEST_ASSERT_EQUAL_INT(1, fib_iterative(0));
    TEST_ASSERT_EQUAL_INT(1, fib_iterative(1));
    TEST_ASSERT_EQUAL_INT(2, fib_iterative(2));
}
