#include "../Unity/src/unity.h"

#include "../datastructures/avl_tree.h"

void test_avl(void) {
    // Test random values
    struct List *input = get_singleton(0);
    input = append(input, get_singleton(1));
    input = append(input, get_singleton(2));
    input = append(input, get_singleton(5));
    input = append(input, get_singleton(5));
    input = append(input, get_singleton(9));
    input = append(input, get_singleton(1));
    input = append(input, get_singleton(4));
    input = append(input, get_singleton(0));

    struct List *solution = get_singleton(0);
    solution = append(solution, get_singleton(1));
    solution = append(solution, get_singleton(2));
    solution = append(solution, get_singleton(4));
    solution = append(solution, get_singleton(5));
    solution = append(solution, get_singleton(9));

    struct Tree *tree = load(empty(), input);
    struct List *output = inorder(tree, get_empty_list());
    TEST_ASSERT_TRUE(check_list_equality(solution, output));

    // Tests ascending values
    input = get_singleton(0);
    input = append(input, get_singleton(1));
    input = append(input, get_singleton(2));
    input = append(input, get_singleton(3));
    input = append(input, get_singleton(4));

    solution = get_singleton(0);
    solution = append(solution, get_singleton(1));
    solution = append(solution, get_singleton(2));
    solution = append(solution, get_singleton(3));
    solution = append(solution, get_singleton(4));

    tree = load(empty(), input);
    output = inorder(tree, get_empty_list());
    TEST_ASSERT_TRUE(check_list_equality(solution, output));

    // Tests descending values
    input = get_singleton(4);
    input = append(input, get_singleton(3));
    input = append(input, get_singleton(2));
    input = append(input, get_singleton(1));
    input = append(input, get_singleton(0));

    solution = get_singleton(0);
    solution = append(solution, get_singleton(1));
    solution = append(solution, get_singleton(2));
    solution = append(solution, get_singleton(3));
    solution = append(solution, get_singleton(4));

    tree = load(empty(), input);
    output = inorder(tree, get_empty_list());
    TEST_ASSERT_TRUE(check_list_equality(solution, output));
}
