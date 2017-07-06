#include <stdlib.h>
#include <stdio.h>

#include "list.h"

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
    if (list == NULL) {
        return list;
    }
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
