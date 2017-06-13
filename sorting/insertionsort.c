#include "../lib/array.h"

void insertionsort(int a[], int n) {
    int pass, min, i, temp;
    for (pass = 0; pass < n - 1; pass++) {
        min = pass;  // initialise subscript min
        for (i = pass + 1; i < n; i++) {
            if (a[i] < a[min]) {
                min = i;  // min so far
            }
        }  // end of each pass
        swap (a, pass, min);
    }  // end of all passes
}
