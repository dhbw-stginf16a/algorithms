#include <stdlib.h>
#include <stdio.h>

int hash_address(int key) {
    return key % 11;
}

int search (int hash_table[], int size, int key) {
    int hash = hash_address(key);
    if (hash_table[hash] == key) {
        return key;
    } else {
        int new_hash = hash;
        do {
            new_hash += 1;
            if (new_hash >= size) {
                new_hash = 0;
                if (new_hash == hash) {
                    break;
                }
            }
            if (hash_table[new_hash] == key) {
                return key;
            }
        } while(new_hash + 1 != hash);
        return -1;
    }
}

void delete(int hash_table[], int size, int key) {
    int hash = hash_address(key);
    if (hash_table[hash] == key) {
        hash_table[hash] = -2;
    } else {
        int new_hash = hash;
        do {
            new_hash += 1;
            if (new_hash >= size) {
                new_hash = 0;
            }
            if (hash_table[new_hash] == key) {
                hash_table[new_hash] = -2;
            }

        } while(new_hash + 1 != hash);
    }
}

// return 1 for success, 0 for failure
int insert (int hash_table[], int size, int key) {
    int hash = hash_address(key);
    if (hash_table[hash] == -1) {
        hash_table[hash] = key;
        return 1;
    } else {
        int new_hash = hash;
        do {
            new_hash += 1;
            if (new_hash >= size) {
                new_hash = 0;
            }
            if (hash_table[new_hash] <= -1) {
                hash_table[new_hash] = key;
                return 1;
            }

        } while(new_hash + 1 != hash);
    }
    return 0;
}
void print_hash_table(int hash_table[], int size) {
    for (int hash = 0; hash < size; ++hash) {
        printf("%d: ", hash);
        for (int i = 0; i < size; ++i) {
            if (hash_address(hash_table[i]) == hash) {
                printf("%d, ", hash_table[i]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void print_array(int hash_table[], int size) {
    for (int i = 0; i < size; i++) {
        if (hash_table[i] <= -1) {
            printf(" | ");
        } else {
            printf("%d | ", hash_table[i]);
        }
    }
    printf("\n");
}

int main(void) {
    const int SIZE = 11;
    int hash_table[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    insert(hash_table, SIZE, 42);
    insert(hash_table, SIZE, 43);
    insert(hash_table, SIZE, 53);
    print_array(hash_table, SIZE);
    print_hash_table(hash_table, SIZE);
    printf("%d %s gefunden\n", 53,  search(hash_table, SIZE, 53) == 53 ? "" : "nicht");
    printf("%d %s gefunden\n\n", 33,  search(hash_table, SIZE, 33) == 33 ? "" : "nicht");
    delete(hash_table, SIZE, 42);
    delete(hash_table, SIZE, 53);
    delete(hash_table, SIZE, 53);
    print_array(hash_table, SIZE);
    print_hash_table(hash_table, SIZE);
    return 0;
}
