#include "../Unity/src/unity.h"

#include "../maths/factorial.h"

void test_fact(void) {
    TEST_ASSERT_EQUAL_INT(1, fact(0));
    TEST_ASSERT_EQUAL_INT(1, fact(1));
    TEST_ASSERT_EQUAL_INT(2, fact(2));
}
