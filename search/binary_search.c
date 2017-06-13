/**
 * Returns index of target string in the given list,
 * or returns -1 if target string is not found.
 */
int binarySearch(char *list[ ], char target[ ], int n) {
    int start, end, middle;
    start = 0;
    end = n - 1;
    while (start <= end) {
        middle = (start + end) / 2;
        if (strcmp(target, list[middle]) < 0) {
            end = middle - 1;
        } else if (strcmp(target, list[middle]) > 0) {
            start = middle + 1;
        } else {
            return middle;
        }
    }  // end while
    return -1;
}  // end binary searchAlgorit
