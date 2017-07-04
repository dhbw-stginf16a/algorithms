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
    return root;
}

struct Tree *balanceLR(struct Tree *root) {
    return root;
}

// just mirror of balanceLR
struct Tree *balanceRL(struct Tree *root) {
    return root;
}

// just the mirror of balanceLL
struct Tree *balanceRR(struct Tree *root) {
    return root;
}

struct Tree *avl_insert(struct Tree *root, int value) {
    return root;
}
