#include <stdlib.h>
#include <stdio.h>

extern int index_comps;
extern int value_comps;
extern int array_accesses;

int smaller(int x, int y);
void merge(int a[], int low, int mid, int high, int aux[]);
void sort(int a[], int low, int high, int aux[]);

/**
 * Do lg n passes of pairwise merges.
 */
void natural_mergesort(int a[], int n) {
    int *aux = (int *) malloc(n * sizeof(int)); // allocate aux array ONCE
    int low, mid, high, check, size1, size2;
    int finished = 0;  // false

    while (!finished) {
        check = 0;
        low = 0;
        while (low < n) {  // low: next pair of strings
            size1 = 1;
            while (low + size1 < n && a[low + size1 - 1] <= a[low + size1]) {
                size1++;  // length of first string
            }
            size2 = 1;
            while (low + size2 < n
                    && a[low + size1 + size2- 1] <= a[low + size1 + size2]) {
                size2++;  //length of second string
            }

            mid = low + size1 - 1;
            high = smaller(low + size1 + size2, n - 1);  // check end of array
            merge(a, low, mid, high, aux);

            low = low + size1 + size2;  // start next pair of sting
            check++;  // number of pairs
        }
        finished = check <= 1;  // no more strings to merge
    }
}

int smaller(int x, int y) {
    return x < y ? x : y;
}

void recursive_mergesort(int a[], int len) {
    int *aux = (int *) malloc(len * sizeof(int)); // allocate aux array
    sort(a, 0, len - 1, aux);
}

void sort(int a[], int low, int high, int aux[]) {
    int mid;
    if (high > low) {
        index_comps++;
        mid = (high + low) / 2;
        sort(a, low, mid, aux);     // left
        sort(a, mid+1, high, aux);  // right
        merge(a, low, mid, high, aux);
    }
}

void merge(int a[], int low, int mid, int high, int aux[]) {
    int i = low;
    int j = mid + 1;
    int k;

    for (k = low; k <= high; k++) {  // Copy a[low..high] to aux[low..high].
        aux[k] = a[k];
        array_accesses += 2;
    }

    for (k = low; k <= high; k++) {  // Merge back to a[low..high].
        if (i > mid) {  // end of 1st half
            index_comps++;
            a[k] = aux[j++]; // rest of 2nd half
            array_accesses += 2;
        } else if (j > high) {  // end of 2nd half
            index_comps += 2;
            a[k] = aux[i++]; // rest of 1st half
            array_accesses += 2;
        } else if (aux[j] < aux[i]) { // compare values
            array_accesses += 2;
            value_comps++;
            a[k] = aux[j++];
            array_accesses += 2;
        } else {
            array_accesses += 2;
            a[k] = aux[i++];
            array_accesses += 2;
        }
    }
}
