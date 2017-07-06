#include <string.h>

#include "../Unity/src/unity.h"

#include "../search/binary_search.h"
#include "../search/linear_search.h"
#include "../search/pattern_matching.h"

#define HAYSTACK "This is the search string"

void test_search(int (*search)(char **, char *, int)) {
    char *haystack[] = {
        "This",
        "is",
        "the",
        "search",
        "string"
    };
    int SIZE = 5;
    char *target = "the";
    char *wrong_target = "waaah";
    TEST_ASSERT_EQUAL_INT(2, search(haystack, target, SIZE));
    TEST_ASSERT_EQUAL_INT(-1, search(haystack, wrong_target, SIZE));
}

void test_binary_search(void) {
    test_search(binary_search);
}

void test_linear_search(void) {
    test_search(linear_search);
}

void test_pattern_matching(int (*match)(char *, char *)) {
    char *haystack = "abacaabaccabacabaabb";
    char *needle = "abacab";

    TEST_ASSERT_EQUAL_INT(6, match(haystack, needle));
}

void test_bruteforce_match(void) {
    test_pattern_matching(bruteforce_match);
}

void test_boyermoore_match(void) {
    test_pattern_matching(boyermoore_match);
}
