#include "../Unity/src/unity.h"

#include "../maths/fibonacci.c"

void test_recursive_fibonacci(void) {
    TEST_ASSERT_EQUAL_INT(1, fib_recursive(0));
    TEST_ASSERT_EQUAL_INT(1, fib_recursive(1));
}
