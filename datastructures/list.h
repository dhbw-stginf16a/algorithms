#ifndef LIST
#define LIST
struct List {
    struct List *next;
    int value;
};
#endif

struct List *get_empty_list();
struct List *get_singleton(int value);
int is_empty(struct List *list);
struct List *append(struct List *left, struct List *right);
struct List *combine(struct List *first, struct List *second, struct List *third);
int get_head(struct List *list);
struct List *pop(struct List *list);
void print_list(struct List *list);
int check_list_equality(struct List *left, struct List *right);
