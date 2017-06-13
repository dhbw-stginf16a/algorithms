/**
 * Returns index of target string in the given list,
 * or returns -1 if target string is not found.
 */
int linearSearch(char *list[ ], char target[ ], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(target, list[i]) == 0) {
            return i;
        }
    } // end for
    return -1;
}  // end linear search
