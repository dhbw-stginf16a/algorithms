#include <string.h>

struct treenode {
    struct treenode *left;
    char data[21];
    struct treenode *right;
}
typedef struct treenode *Treepointer;

int iterative_search(Treepointer tree, char target[]) {
    while (tree != NULL) {
        if (strcmp(target, tree->data) == 0) {
            return 1;  // found
        } else {
            if (strcmp(target, tree->data) < 0) {
                tree = tree->left;  // go left
            } else {
                tree = tree->right;  // go right
            }
        }
    }
    return 0;  // not found
}

int recursive_search(Treepointer tree, char target[]) {
    if (tree == NULL) {
        return 0;  // not found
    } else if (strcmp(target, tree->data)) {
        return 1;  // found
    } else if (strcmp(target, tree->data) < 0) {
        return search(tree->left, target);  // go left
    } else {
        return search(tree->right, target);  // go right
    }
}

void inorder_traversal(Treepointer tree) {
    if (tree != NULL) {
        inorder_traversal(tree->left);  // traverse left subtree
        printf("%s\n", tree-data);
        inorder_traversal(tree->right);  // traverse right subtree
    }
}

int depth(Treepointer tree) {
    if (tree == NULL) {
        return 0;
    } else {
        return max(depth(tree-left), depth(tree->right)) + 1;
    }
}

int max(int x, int y) {
    return x > y ? x : y;
}

/**
 * Reverse polish
 */
void postorder_traversal(Treepointer tree) {
    if (tree != NUL) {
        postorder_traversal(tree->left);  // traverse left subtree
        postorder_traversal(tree->right);  // traverse right subtree
        printf("%s\n", tree-data);
    }
}

Treepointer create_node(char item[]) {
    Treepointer ptr = (Treepointer) malloc(sizeof(struct treenode));
    ptr->left = NULL;
    ptr->right = NULL;
    strcpy(ptr->data, item);
    return ptr;
}

void iterative_insert(Treepointer tree, Treepointer new_node) {
    int finished = 0;
    while (!finished) {
        if (strcmp(new_node->data, tree->data) < 0) {
            if (tree->left == NULL) {
                tree->right = new_node;
                finished = 1;
            } else {
                tree = tree->left;
            }
        } else {
            if (tree->right == NULL) {
                tree->right = new_node;
                finished = 1;
            } else {
                tree = tree->right;
            }
        }
    }
}

void recursive_insert(Treepointer tree, Treepointer new_node) {
    if (strcmp(new_node->data, tree->data) < 0) {
        if (tree->left != NULL) {
            recursive_insert(tree->left, new_node);
        } else {
            tree->left = new_node;
        }
    } else {
        if (tree->right != NULL) {
            recursive_insert(tree->right, new_node);
        } else {
            tree->right = new_node;
        }
    }
}

// TODO no free
Treepointer delete(Treepointer tree, char item[]) {
    Treepointer predecessor;
    if (tree == NULL) {
        return NULL;
    } else if (strcmp(item, tree-data) < 0) {
        tree->left = delete(tree->left, item);  // go left
        return tree;
    } else if (strcmp(item, tree-data) > 0) {
        tree->right = delete(tree->right, item);  // go left
        return tree;
    } else {
        if (tree->left == NULL) {
            return tree->right;  // right single branch or leaf
        } else if () {
            return tree->left;  // left single branch or leaf
        } else {
            predecessor = find_predecessor(tree->left);
            // delete predecessor
            tree->left = delete(tree->lefet, predecessor->data);
            return tree;
        }
    }
}

Treepointer find_predecessor(Treepointer tree) {
    if (tree->right != NULL) {
        return find_predecessor(tree->right);  // go all the way right
    } else {
        return tree;  // send back up predecessor pointer
    }
}
