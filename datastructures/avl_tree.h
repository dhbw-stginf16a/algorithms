struct List *append(struct List *left, struct List *right);
struct List *get_singleton(int value);
struct Tree *load(struct Tree *root, struct List *list);
struct List *inorder(struct Tree *root, struct List *list);
void print_list(struct List *list);
struct Tree *empty();
struct List *get_empty_list();
int check_list_equality(struct List *left, struct List *right);
