#include <stdlib.h>
#include <stdio.h>

struct Node {
    int value;
    struct Node  *next;
};

struct Node *new_node(int value) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

int hash_adress (int key) {
    return key % 3;
}

void insert(struct Node *hash_table[], int key) {
    int hash = hash_adress(key);
    struct Node* new  = new_node(key);
    if (hash_table[hash] == NULL) {
        hash_table[hash] = new;
    } else {
        struct Node* pointer = hash_table[hash];
        while(pointer->next != NULL){
            pointer = pointer->next;
        }
        pointer->next = new;
    }
}

void print_linked_list(struct Node *list) {
    struct Node* pointer = list;
    while(pointer != NULL) {
        printf("%d, ", pointer->value);
        pointer = pointer->next;
    }
    printf("NULL\n");
}

void print_hash_table(struct Node *hash_table[], int size) {
    for (int i = 0; i < size; i++){
        printf("%d: ", i);
        print_linked_list(hash_table[i]);
    }
}

struct Node *delete_node(struct Node *list, int value) {
    if (list == NULL) {
        return NULL;
    } else {
        // first node is the target
        if (list->value == value) {
            struct Node *next = list->next;
            free(list);
            return next;
        }
        struct Node *head = list;

        struct Node *pointer = list;
        while (pointer->next != NULL) {
            if (pointer->next->value == value) {
                struct Node *new_next = pointer->next->next;
                free(pointer->next);
                pointer->next = new_next;
            } else {
                pointer = pointer->next;
            }
        }
        return head;

   }
}

void delete(struct Node *hash_table[], int key) {
    int hash = hash_adress(key);
    struct Node *list = hash_table[hash];
    hash_table[hash] = delete_node(list, key);
}

struct Node *search(struct Node *hash_table[], int key) {
    int hash = hash_adress(key);
    struct Node *pointer = hash_table[hash];
    do {
        if (pointer->value == key) {
            return pointer;
        } else if (pointer->next != NULL) {
            pointer = pointer->next;
        } else {
            break;
        }
    } while (pointer);
    return NULL;
}

int main(void) {
    const int SIZE = 3;
    struct Node *hash_table[] = {NULL, NULL, NULL};

    insert(hash_table, 7);
    insert(hash_table, 5);
    insert(hash_table, 6);
    insert(hash_table, 4);
    insert(hash_table, 7);
    insert(hash_table, 8);

    printf("Before\n");
    print_hash_table(hash_table, SIZE);

    //delete(hash_table, 0);
    //delete(hash_table, 6);
    //delete(hash_table, 7);
    //delete(hash_table, 7);
    //delete(hash_table, 8);
    //delete(hash_table, 5);
    //delete(hash_table, 4);

    printf("\n");
    printf("Found: ");
    print_linked_list(search(hash_table, 6));
    printf("Found: ");
    print_linked_list(search(hash_table, 4));
    printf("Found: ");
    print_linked_list(search(hash_table, 5));
    printf("Found: ");
    print_linked_list(search(hash_table, 8));
    printf("Found: ");
    print_linked_list(search(hash_table, 42));

    printf("\nAfter\n");
    print_hash_table(hash_table, SIZE);
    return 0;
}
