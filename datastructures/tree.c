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
        //print_tree(root, 2);
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

int trees_equal(struct Tree *first, struct Tree *second) {
    if (first == NULL && second == NULL) {
        return 1;
    } else if (first == NULL || second == NULL) {
        return 0;
    } else {
        if (first->value == second->value) {
            return trees_equal(first->left, second->left) && trees_equal(first->right, second->right);
        } else {
            return 0;
        }
    }
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

// https://stackoverflow.com/a/41105372/5932056
#define space 4
void draw_tree_hor2(struct Tree *tree, int depth, char *path, int right)
{
    // stopping condition
    if (tree== NULL)
        return;

    // increase spacing
    depth++;

    // start with right node
    draw_tree_hor2(tree->right, depth, path, 1);

    // set | draw map
    path[depth-2] = 0;

    if(right)
        path[depth-2] = 1;

    if(tree->left)
        path[depth-1] = 1;

    // print root after spacing
    printf("\n");

    for(int i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<space; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }

    printf("%d\n", tree->value);

    // vertical spacers below
    for(int i=0; i<depth; i++)
    {
      if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<space; j++)
          printf(" ");
    }

    // go to left node
    draw_tree_hor2(tree->left, depth, path, 0);
}

//primary fuction
void draw_tree_hor(struct Tree *tree)
{
    // should check if we don't exceed this somehow..
    char path[1024] = {};

    //initial depth is 0
    draw_tree_hor2(tree, 0, path, 0);
    printf("\n");
}
