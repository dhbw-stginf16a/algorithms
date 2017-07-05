#include <stdlib.h>
#include <stdio.h>

#include "avl_tree.h"
#include "list.h"
#include "tree.h"

int bal_factor(struct Tree *left, struct Tree *right) {
    int left_depth = depth(left);
    int right_depth = depth(right);
    return depth(left) - depth(right);
}

struct Tree *balance_ll(struct Tree *root) {
    struct Tree *clone = clone_tree(root);

    clone->value = root->left->value;
    clone->left = clone_tree(root->left->left);
    clone->right = clone_tree(root);
    clone->right->left = clone_tree(root->left->right);
    //printf("LL: root: %d cloned: %d\n", root->value, clone->value);

    return clone;
}

struct Tree *balance_lr(struct Tree *root) {
    struct Tree *clone = clone_tree(root);

    clone->value = root->left->right->value;
    clone->right = clone_tree(root);
    clone->right->left = clone_tree(root->left->right->right);
    clone->left->right = clone_tree(root->left->right->left);
    //printf("LR: root: %d cloned: %d\n", root->value, clone->value);

    return clone;
}

// just mirror of balanceLR
struct Tree *balance_rl(struct Tree *root) {
    struct Tree *clone = clone_tree(root);

    clone->value = root->right->left->value;
    clone->left = clone_tree(root);
    clone->left->right = clone_tree(root->right->left->left);
    clone->right->left = clone_tree(root->right->left->right);
    //printf("RL: root: %d cloned: %d\n", root->value, clone->value);

    return clone;
}

// just the mirror of balanceLL
struct Tree *balance_rr(struct Tree *root) {
    struct Tree *clone = clone_tree(root);

    clone->value = root->right->value;
    clone->right = clone_tree(root->right->right);
    clone->left  = clone_tree(root);
    clone->left->right = clone_tree(root->right->left);
    //printf("RR: root: %d cloned: %d\n", root->value, clone->value);

    return clone;
}

struct Tree *avl_insert(struct Tree *root, int value) {
    if (root == NULL) {
        return leaf(value);
    }

    struct Tree *left = clone_tree(root->left);
    struct Tree *leftI = avl_insert(clone_tree(root->left), value);
    struct Tree *right = clone_tree(root->right);
    struct Tree *rightI = avl_insert(clone_tree(root->right), value);


    if (root->value == value) {
        return root;
    } else if (value < root->value && bal_factor(leftI, right) ==  2 && value < left->value) {
        return balance_ll(node(leftI, right, root->value));
    } else if (value < root->value && bal_factor(leftI, right) ==  2 && value > left->value) {
        return balance_lr(node(leftI, right, root->value));
    } else if (value > root->value && bal_factor(left, rightI) == -2 && value < right->value) {
        return balance_rl(node(left, rightI, root->value));
    } else if (value > root->value && bal_factor(left, rightI) == -2 && value > right->value) {
        return balance_rr(node(left, rightI, root->value));
    } else if (value < root->value) {
        return node(leftI, right, root->value);
    } else if (value > root->value) {
        return node(left, rightI, root->value);
    }
}
