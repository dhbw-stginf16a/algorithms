#include "../Unity/src/unity.h"

#include "../datastructures/avl_c/avl_tree.h"
#include "../datastructures/avl_c/tree.h"
#include "../datastructures/avl_c/list.h"

void test_avl(void) {
    struct List *list;
    int values[] = {
        6, 3, 4, 8, 7, 9, 5, 6, 8, 10, 11, 12
    };
    struct Tree *search_tree;
    //search_tree = from_array(values, sizeof(values) / sizeof(int), insert);
    //list = inorder(search_tree);
    //print_list(list);
    //print_tree(search_tree);

    struct Tree *avl_tree;
    int simple_vals[] = {2, 1, 4, 3, 5};
    avl_tree = from_array(simple_vals, sizeof(simple_vals) / sizeof(int), insert);
    //list = inorder(avl_tree);
    //print_list(list);
    print_tree(avl_tree);

//    // Test random values
//    struct List *input = get_singleton(0);
//    input = append(input, get_singleton(1));
//    input = append(input, get_singleton(2));
//    input = append(input, get_singleton(5));
//    input = append(input, get_singleton(5));
//    input = append(input, get_singleton(9));
//    input = append(input, get_singleton(1));
//    input = append(input, get_singleton(4));
//    input = append(input, get_singleton(0));
//
//    struct List *solution = get_singleton(0);
//    solution = append(solution, get_singleton(1));
//    solution = append(solution, get_singleton(2));
//    solution = append(solution, get_singleton(4));
//    solution = append(solution, get_singleton(5));
//    solution = append(solution, get_singleton(9));
//
//    struct Tree *tree = load(empty(), input);
//    struct List *output = inorder(tree, get_empty_list());
//    TEST_ASSERT_TRUE(check_list_equality(solution, output));
//
//    // Tests ascending values
//    input = get_singleton(0);
//    input = append(input, get_singleton(1));
//    input = append(input, get_singleton(2));
//    input = append(input, get_singleton(3));
//    input = append(input, get_singleton(4));
//
//    solution = get_singleton(0);
//    solution = append(solution, get_singleton(1));
//    solution = append(solution, get_singleton(2));
//    solution = append(solution, get_singleton(3));
//    solution = append(solution, get_singleton(4));
//
//    tree = load(empty(), input);
//    output = inorder(tree, get_empty_list());
//    TEST_ASSERT_TRUE(check_list_equality(solution, output));
//
//    // Tests descending values
//    input = get_singleton(4);
//    input = append(input, get_singleton(3));
//    input = append(input, get_singleton(2));
//    input = append(input, get_singleton(1));
//    input = append(input, get_singleton(0));
//
//    solution = get_singleton(0);
//    solution = append(solution, get_singleton(1));
//    solution = append(solution, get_singleton(2));
//    solution = append(solution, get_singleton(3));
//    solution = append(solution, get_singleton(4));
//
//    tree = load(empty(), input);
//    output = inorder(tree, get_empty_list());
//    TEST_ASSERT_TRUE(check_list_equality(solution, output));
}
