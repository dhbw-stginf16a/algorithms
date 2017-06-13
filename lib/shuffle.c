#include <stdlib.h>

#include "shuffle.h"
#include "array.h"

/**
 * Shuffle the array using the Knuth/Fisher-Yates algorithm.
 */
void shuffle(int a[], int len) {
    for (int i = len - 1; i > 0; i--) {
        swap(a, i, rand() % i);
    }
}
