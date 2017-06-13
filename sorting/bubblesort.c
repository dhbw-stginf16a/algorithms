#include "../lib/array.h"

void bubblesort(int a[], int n) {
    int comps, i, temp;
    for (comps = n - 1; comps >= 1; comps--) {
                 // comparisons reduce on each pass
        for (i = 0; i < comps; i++) {
            if (a[i] > a[i + 1]) {
                swap(a, i, i + 1);
            }
        }  // end of each pass
    }  // end of all passes
}

void flagged_bubblesort(int a[], int n) {
    int i, temp, comps, sorted = 0;
    comps = n - 1;

    while (!sorted) {
        sorted = 1;
        for (i = 0; i < comps; i++) {
            if (a[i] > a[i + 1]) {
                swap(a, i, i + 1);
                sorted = 0;  // not yet sorted
            }
        }  // end of each pass
        comps--;
    }  // end of all passes
}

void shuttlesort(int a[], int n) {
    int temp, i, j;
    for (i = 0; i < n - 1; i++) {  // primary pass
        if (a[i] > a[i + 1]) {
            j = i - 1;
            temp = a[i + 1];
            a[i + 1] = a[i];
            while (j >= 0 && a[j] > temp) {  // go back
                a[j + 1] = a[j];  // shuffle values forward
                j = j - 1;
            }  // end secondary pass
            a[j + 1] = temp;  // insert small value further back
        }  // else no secondary pass
    }  // end all passes
}
