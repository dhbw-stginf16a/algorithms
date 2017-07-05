#include <stdlib.h>
#include <stdio.h>

#include "tree.h"
#include "list.h"

#define RED   "\x1B[31m"
#define RESET "\x1B[0m"

struct Tree *node(struct Tree *left, struct Tree *right, int value) {
    struct Tree *node = malloc(sizeof(struct Tree));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

struct Tree *insert(struct Tree *root, int value) {
    if (root == NULL) {
        return leaf(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

struct Tree *from_array(
        int *array, int len,
        struct Tree *(*insert_alg)(struct Tree *, int)
    ) {
    struct Tree *root = empty();
    for (int i = 0; i < len; ++i) {
        root = (*insert_alg)(root, array[i]);
        print_tree(root, 2);
    }
    return root;
}

struct Tree *leaf(int value) {
    struct Tree *leaf = malloc(sizeof(struct Tree));
    leaf->left = NULL;
    leaf->right = NULL;
    leaf->value = value;
    return leaf;
}

struct Tree *empty() {
    return NULL;
}

int max(int left, int right) {
    return left > right ? left : right;
}

int depth(struct Tree *root) {
    if (root == NULL) {
        return 0;
    }
    int left_depth = depth(root->left);
    int right_depth = depth(root->right);
    return max(left_depth, right_depth) + 1;
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

struct List *inorder(struct Tree *root) {
    if (root == NULL) {
        return get_empty_list();
    }
    return combine(
            inorder(root->left),
            get_singleton(root->value),
            inorder(root->right)
    );
}

// -- printing
void show_trunks(struct Trunk *p) {
	if (!p) return;
	show_trunks(p->prev);
	printf("%s", p->str);
}

void show_tree(struct Tree *root, struct Trunk *prev, int is_left, int balance) {
	if (root == NULL) return;

	struct Trunk this_disp = { prev, "    " };
	char *prev_str = this_disp.str;
	show_tree(root->left, &this_disp, 1, balance);

	if (!prev)
		this_disp.str = "────";
	else if (is_left) {
		this_disp.str = "┌──";
		prev_str = "    │";
	} else {
		this_disp.str = "└──";
		prev->str = prev_str;
	}

	show_trunks(&this_disp);

    if (balance == 2) {
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        char balance_indicator = 'E';
        if (left_depth < right_depth) {
            balance_indicator = 'R';
        } else if (left_depth > right_depth){
            balance_indicator = 'L';
        }
        printf(RED " %d " RESET "%c\n", root->value, balance_indicator);
    } else if (balance) {
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        printf(RED " %d " RESET "(%d - %d = %d)\n", root->value, left_depth, right_depth, left_depth - right_depth);
    } else {
	    printf(RED " %d\n" RESET, root->value);
    }

	if (prev) prev->str = prev_str;
	this_disp.str = "    │";

	show_tree(root->right, &this_disp, 0, balance);
	if (!prev) puts("");
}

void print_tree(struct Tree *root, int balance) {
    show_tree(root, 0, 0, balance);
}
