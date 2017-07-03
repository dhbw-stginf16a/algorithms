#include <stdlib.h>
#include <stdio.h>
#include <sys/queue.h>

#include "avl_tree.h"
#define max(a,b) ((a) > (b) ? a : b)

//---------- LIST START ----------
struct List {
    struct List *next;
    int value;
};

struct List *get_empty_list() {
    return NULL;
}

struct List *get_singleton(int value) {
    struct List *singleton = malloc(sizeof(struct List));
    singleton->value = value;
    singleton->next = NULL;
    return singleton;
}

int is_empty(struct List *list) {
    return list == NULL;
}

struct List *append(struct List *left, struct List *right) {
    if (left == NULL && right == NULL) {
        return get_empty_list();
    } if (left == NULL) {
        return right;
    } else if (right == NULL) {
        return left;
    }
    struct List *cursor = left;
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    cursor->next = right;
    return left;
}

struct List *combine(struct List *first, struct List *second, struct List *third) {
    return append(first, append(second, third));
}

int get_head(struct List *list) {
    return list->value;
}

struct List *pop(struct List *list) {
    struct List *new_list = list->next;
    free(list);
    return new_list;
}

void print_list(struct List *list) {
    while (list != NULL) {
        printf("%d, ", list->value);
        list = list->next;
    }
    printf("\n");
}

int check_list_equality(struct List *left, struct List *right) {
    if (left == right) {
        return 1;
    } else if (left == NULL || right == NULL) {
        return 0;
    }
    if (left->value == right->value) {
        return 1;
    } else {
        return check_list_equality(pop(left), pop(right));
    }
}

//---------- LIST END ----------

struct Tree {
    struct Tree *left;
    struct Tree *right;
    int value;
};

struct Tree *empty() {
    return NULL;
}

struct Tree *clone_tree(struct Tree *root) {
    if (root == NULL) {
        return root;
    }

    struct Tree *new_node = malloc(sizeof(struct Tree));
    new_node->value = root->value;
    new_node->left = clone_tree(root->left);
    new_node->right = clone_tree(root->right);
    return new_node;
}

int depth(struct Tree *root) {
    if (root == NULL) {
        return 0;
    }
    int left_depth = depth(root->left);
    int right_depth = depth(root->right);
    return max(left_depth, right_depth) + 1;
}

struct List *inorder(struct Tree *root, struct List *list) {
    if (root == NULL) {
        return get_empty_list();
    }
    return combine(
            inorder(root->left, get_empty_list()),
            get_singleton(root->value),
            inorder(root->right, get_empty_list())
    );
}

int balFactor(struct Tree *left, struct Tree *right) {
    int left_depth = depth(left);
    int right_depth = depth(right);
    return depth(left) - depth(right);
}

struct Tree *balanceLL(struct Tree *root) {
    int tmp_val;
    struct Tree *tmp;

    tmp_val = root->value;
    root->value = root->left->value;
    root->left->value = tmp_val;

    tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    tmp = root->left;
    root->left = root->right->left;
    root->right->left = root->right->right;
    root->right->right = tmp;

    return root;
}

struct Tree *balanceLR(struct Tree *root) {
    int tmp_val;
    struct Tree *tmp;

    tmp_val = root->left->right->value;
    root->left->right->value = root->value;
    root->value = tmp_val;

    tmp = root->left->right->left;
    root->left->right->left = root->left->right->right;
    root->left->right->right = root->right;
    root->right = tmp;

    tmp = root->right;
    root->right = root->left->right;
    root->left->right = tmp;

    return root;
}

// just mirror of balanceLR
struct Tree *balanceRL(struct Tree *root) {
    int tmp_val;
    struct Tree *tmp;

    tmp_val = root->right->left->value;
    root->right->left->value = root->value;
    root->value = tmp_val;

    tmp = root->right->left->right;
    root->right->left->right = root->right->left->left;
    root->right->left->left = root->left;
    root->left = tmp;

    tmp = root->left;
    root->left = root->right->left;
    root->right->left = tmp;

    return root;
}

// just the mirror of balanceLL
struct Tree *balanceRR(struct Tree *root) {
    int tmp_val;
    struct Tree *tmp;

    tmp_val = root->value;
    root->value = root->right->value;
    root->right->value = tmp_val;

    tmp = root->right;
    root->right = root->left;
    root->left = tmp;

    tmp = root->right;
    root->right = root->left->right;
    root->left->right = root->left->left;
    root->left->left = tmp;

    return root;
}

struct Tree *get_leaf(int value) {
    struct Tree *leaf = malloc(sizeof(struct Tree));
    leaf->left = NULL;
    leaf->right = NULL;
    leaf->value = value;
    return leaf;
}

struct Tree *create_node(struct Tree *left, struct Tree *right, int value) {
    struct Tree *node = malloc(sizeof(struct Tree));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

struct Tree *insert(struct Tree *root, int value) {
    if (root == NULL) {
        return get_leaf(value);
    }

    struct Tree *left = root->left;
    struct Tree *right = root->right;
    struct Tree *leftI = insert(clone_tree(left), value);
    struct Tree *rightI = insert(clone_tree(right), value);

    if (root->value == value) {
        return root;
    } else if (value > root->value && balFactor(left, rightI) ==  2 && value > left->value) {
        return balanceRR(create_node(left, rightI, root->value));
    } else if (value > root->value && balFactor(left, rightI) ==  2 && value < left->value) {
        return balanceRL(create_node(left, rightI, root->value));
    } else if (value < root->value && balFactor(leftI, right) == -2 && value < left->value) {
        return balanceLL(create_node(leftI, right, root->value));
    } else if (value < root->value && balFactor(leftI, right) == -2 && value > left->value) {
        return balanceLR(create_node(leftI, right, root->value));
    } else if (value < root->value) {
        return create_node(leftI, right, root->value);
    } else if (value > root->value) {
        return create_node(left, rightI, root->value);
    }
}

struct Tree *load(struct Tree *root, struct List *list) {
    if (is_empty(list))  {
        return root;
    }

    int x = get_head(list);
    list = pop(list);
    return insert(load(root, list), x);
}
