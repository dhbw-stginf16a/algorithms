#ifndef LIST
#define LIST
struct List {
    struct List *next;
    int value;
};
#endif

struct Tree {
    struct Tree *left;
    struct Tree *right;
    int value;
};

struct Trunk {
	struct Trunk *prev;
	char * str;
};

struct Tree *node(struct Tree *left, struct Tree *right, int value);
struct Tree *insert(struct Tree *root, int value);
struct Tree *from_list(struct Tree *root, struct List *list);
struct Tree *from_array(
        int *array, int len,
        struct Tree *(*insert_alg)(struct Tree *, int)
);
struct Tree *leaf(int value);
struct Tree *empty();
int depth(struct Tree *root);
struct Tree *clone_tree(struct Tree *root);
struct List *inorder(struct Tree *root);
void print_tree(struct Tree *root);
