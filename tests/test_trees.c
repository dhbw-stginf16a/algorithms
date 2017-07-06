#include "../Unity/src/unity.h"

#include "../datastructures/avl_tree.h"
#include "../datastructures/tree.h"
#include "../datastructures/list.h"

void test_rotation(struct Tree*(*rotate)(struct Tree *), int *values, int len) {
    struct Tree *tree = from_array(values, len, insert);
    //printf("before\n");
    //print_tree(tree, 0);
    tree = (*rotate)(tree);
    //printf("after\n");
    //print_tree(tree, 0);
    TEST_ASSERT_TRUE(is_balanced(tree));
}

void test_balancing(void) {
    struct Tree *avl_tree;
    struct List *list;

    int left_left[] = {4, 2, 1, 5, 3};
    test_rotation(balance_ll, left_left, 5);

    int right_right[] = {2, 1, 4, 3, 5};
    test_rotation(balance_rr, right_right, 5);

    int left_right[] = {6, 2, 1, 4, 3, 5, 7};
    test_rotation(balance_lr, left_right, 7);

    int right_left[] = {2, 1, 6, 4, 3, 5, 7};
    test_rotation(balance_rl, right_left, 7);
}

void test_balance_undo(void) {
    struct Tree *before;
    struct Tree *after;

    // LL and then RR returns to original tree
    int left_left[] = {4, 2, 1, 5, 3};
    before = from_array(left_left, 5, insert);
    after = balance_ll(before);
    after = balance_rr(after);
    TEST_ASSERT_TRUE(trees_equal(before, after));

    // LR and RL bring it to the same tree
    int left_right[] = {6, 2, 1, 4, 3, 5, 7};
    before = from_array(left_right, 7, insert);
    struct Tree *after_lr = balance_lr(before);

    int right_left[] = {2, 1, 6, 4, 3, 5, 7};
    before = from_array(right_left, 7, insert);
    struct Tree *after_rl = balance_rl(before);
    TEST_ASSERT_TRUE(trees_equal(after_lr, after_rl));
}

void test_exercise_tree(void) {
    int bsl_values[] = {100, 60, 50, 70, 80, 300, 150, 125, 140, 180, 170, 200, 400, 350, 500};
    int avl_values[] = {200,300,400,500,350,100,125,50,60,70,80,150,180,170,140};
    struct Tree *bsl = from_array(bsl_values, 15, insert);
    struct Tree *avl = from_array(avl_values, 15, avl_insert);

    TEST_ASSERT_TRUE(trees_equal(bsl, avl));

    TEST_ASSERT_TRUE(is_balanced(avl));
}

void test_avl(void) {
    test_balancing();
    test_balance_undo();
    test_exercise_tree();
}
