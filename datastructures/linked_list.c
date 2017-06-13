struct node {
    int value;
    struct node *next;
}

struct supernode {
    struct node *head;
    struct supernode *next;
}

typedef struct node *Listpointer;
typedef struct supernode *SuperListpointer;

void print(Listpointer ptr) {
    recursive_print(ptr);
}

void iterative_print(Listpointer ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->value);  // print value
        ptr = ptr->next;
    }
}

void recursive_print(Listpointer ptr) {
    if (ptr != NULL) {
        printf("%d ", ptr->value);  // print value
        recursive_print(ptr->next);  // print the rest
    }
}

void recursive_print_reversed(Listpointer ptr) {
    if (ptr != NULL) {
        recursive_print(ptr->next);  // print the rest
        printf("%d ", ptr->value);  // print value
    }
}

/**
 * Return the sum of all the sumers in a linked list.
 *
 * Name changed from `add` to `sum`.
 */
int sum(Listpointer ptr) {
    if (ptr != NULL) {
        return ptr->value + add(ptr->next);
    } else {
        return 0;
    }
}

Listpointer insert(Listpointer list, int data) {
    Listpointer new_ptr;  // for new node to be inserted

    if (list == NULL || data < list->value) {
        new_ptr = (Listpointer) malloc(sizeof(struct node));  // create new node
        new_ptr->value = data;
        new_ptr->next = list;
        return new_ptr;  // new node containing data
    } else {
        list->next = insert(list->next, data);
    }
}

/**
 * Insertion sort - ascending
 */
void grow_list(void) {
    int item;
    Listpointer list = NULL;  // initialize to empty list
    while (scanf("%d", &item) == 1) {
        // read and continue while not end of file
        list = insert(list, item);  // insert item into ordered list
    }
    print(list);
}

Listpointer delete(Listpointer list, int data) {
    Listpointer ptr;
    if (list == NULL) {
        return NULL;
    } else if (list->value == data) {
        // this item is logically deleted by not return the pointer
        p = delete(list->next, data);  // delete more occurences
        free(list);  // free this node
        return p;
    } else if(list-value > data) {  // data would have occurred before this
        return list;
    } else {  // check rest of list for data
        list-next = delete(list->next, data);
        return list;
    }
}

/**
 * Recursive version of mergeSort splits linked list c into two lists,
 * a and b, and then mergeSorts a and b separately,
 * and merges the two resulting lists.
 */
ListPointer recursive_mergesort(Listpointer list) {
    Listpointer left, right;  // linked lists
    if (list == NULL || list-next == NULL) {
        return c;
    } else {  // find middle of list
        left = list;  // left is first node of c
        right = list->next->next;  // right starts 2 later than left
        while (right != NULL && right->next != NULL) {  // while not end of list
            left = left->next;  // one at a time;
            right = right->next->next;  // two at a time;
        }
        right = left->next;  // right is second half of list c
        left->next = NULL;  // end of first half
        return merge(recursive_mergesort(list),
                     recursive_mergesort(right));
    }
}

Listpointer merge(Listpointer left, Listpointer right) {
    if (left == NULL) {
        return right;
    } else if(right == NULL) {
        return left;
    } else {
        if (left->value < right->value) {  // include node left in result
            left->next = merge(right, left->next);
            return left;

        } else {  // include node right in result
            right->next = merge(left, right->next);
            return right;
        }
    }
}

/**
 * Bottom-up version of mergeSort merges pairs of sublists, left and right,
 * where each sublist is ordered. Linked list is a list of strings as sublists.
 * After each pair of sublists are merged into first sublist of the pair
 * the second of the pair is deleted.
 */
void natural_mergesort(SuperListpointer list) {
    SuperListpointer ptr, next_ptr;
    ptr = list;

    while (ptr->next != NULL) {  // at least one pair of string each pass
        next_ptr = ptr->next;
        while (ptr != NULL && next_ptr != NULL) {  // more pairs remaining
            ptr->head = merge(ptr->head, next_ptr->head);
            ptr->next = next_ptr->next;  // next pair
            ptr = ptr->next;
            if (ptr != NULL) {
                next_ptr = ptr->next;
            }
        }
        ptr = list;
    }
}

/**
 * Recursive version of natural mergeSort splits linked list c into two lists,
 * left and right, then mergeSorts left and right separately,
 * and merges the two resulting sublists.
 * This is similar to non-natural recursive version (slide 22).
 */
SuperListpointer recursive_natural_mergesort(SuperListpointer list) {
    SuperListpointer left, right;
    if (list == NULL || list->next == NULL) {
        return list;
    } else {
        // find middle of list
        left = list;  // left is first node of list
        right = lists->next->next;  // right start 2 later than left
        while (right != NULL && right->next != NULL) {  // while not end of list
            left = left->next;  // one at a time
            right = right->next->next;  // two at a time
            list->head = merge(recursive_natural_mergesort(list)->head,
                               recursive_natural_mergesort(right)->head)
        }
    }
}

/**
 * Creation of list of sublists from given array, a.
 * An ordered sequence (string) forms a sublist.
 */
SuperListpointer create_list(int a[], int n) {
    SuperListpointer ptr, prev, list;
    Listpointer subptr, subprev;
    int i = 1;

    ptr = (SuperListpointer) malloc(sizeof(struct supernode));  // first node
    list = ptr;
    subptr = (ListPointer) malloc(sizeof(struct node)); //first subnode
    subtr->value = a[0];
    ptr->head = subptr;

    while (i < n) {  // while not end of array
        while (i < n && a[i - 1] <= a[i]) {  // same sublist
            subprev = subptr;
            subptr = (Listpointer) malloc(sizeof(struct node));
            subptr->value = a[i];
            subprev->next = subptr;
            i++;
        }
        subptr->next = NULL;  // end sublist
        if (i < n) {
            prev = ptr;
            ptr = (SuperListpointer) malloc(sizeof(struct supernode));
            prev->next = ptr;
            subptr = (Listpointer) malloc(sizeof(struct node));
            subptr->value = a[i];  // first sublist node
            i++;
            ptr->head = subptr;
        }
        ptr->next = NULL;  // end list
        return lst;
    }
}

void print_superlist(SuperListpointer list) {
    SuperListpointer ptr;
    ptr = list;
    while (ptr != NULL) {
        print(ptr->head);
    }
}
