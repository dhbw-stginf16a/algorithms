#include "../Unity/src/unity.h"

#include "../datastructures/avl_c/avl_tree.h"
#include "../datastructures/avl_c/tree.h"
#include "../datastructures/avl_c/list.h"

void print_test_tree(struct Tree *(*insert_alg)(struct Tree *, int)) {
    struct List *list;
    int values[] = {
        //6, 3, 4, 8, 7, 9, 5, 6, 8, 10, 11, 12
        200,300,400,500,350,100,125,50,60,70,80,150,180,170,140,
        //201,304,404,580,359,106,121,51,10,40,87,1507184,174,144,
        //220,330,460,590,454,140,115,22,61,71,82,122,155,171,141
    };
    struct Tree *tree;
    tree = from_array(values, sizeof(values) / sizeof(int), insert_alg);
    list = inorder(tree);
    print_list(list);
    print_tree(tree, 1);
}

void print_balancing(void) {
    struct Tree *avl_tree;
    struct List *list;

    //int simple_vals[] = {4, 2, 1, 5, 3}; // LL
    //int simple_vals[] = {2, 1, 4, 3, 5}; // RR
    //int simple_vals[] = {6, 2, 1, 4, 3, 5, 7}; // LR
    int simple_vals[] = {2, 1, 6, 4, 3, 5, 7}; // RL
    avl_tree = from_array(simple_vals, sizeof(simple_vals) / sizeof(int), insert);
    print_tree(avl_tree, 0);
    avl_tree = balance_rl(avl_tree);
    print_tree(avl_tree, 0);

    list = inorder(avl_tree);
    print_list(list);
}

void test_avl(void) {
    print_test_tree(avl_insert);
    //print_balancing();


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
