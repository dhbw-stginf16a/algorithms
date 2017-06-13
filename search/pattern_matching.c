#include <stdlib.h>

/**
 * @param char s[] source string
 * @param char p[] pattern
 */
int bruteforcematch(char s[], char p[]) {
    int n, m, i, j; n = strlen(s); m = strlen(p);
    for (i = 0; i <= n – m; i++) {  // for each pattern comparison
        j = 0;
        while (j < m && s[i+j] == p[j]) {  // each character comparison
            j++;
        }  // end while
        if (j == m) {
            return i;
        } else {
            return -1;  // not matched
        }
    } // end for
}

/**
 * @param char s[] source string
 * @param char p[] pattern
 */
int boyermoore_match(char s[], char p[]) {
    int n, m, i, j, lastch; n = strlen(s); m = strlen(p);
    i = m – 1;
    j = m – 1;
    while (i < n) {  // not end of string s
        if (p[j] == s[i]) {
            if (j == 0) {  // first char of pattern
                return i;
            } else {
                // go left
                j--;
                i--;
        } else {  // no match – find char in pattern
            lastch = find(p, s[i]);
            if (lastch == -1) {  // not found
                i = i + m;  // jump over
            else {
                i = i + j – lastch; // align char
            }
            j = m – 1;  // restart from right
        }
    }
    return -1;  // not matched
}

/**
 * Function find(p, ch) returns the index of the rightmost occurrence of
 * character, ch, in the pattern, p.
 * It returns -1 if the character, ch, is not found in pattern, p.
 */
int find(char p[], char ch) {
    int m, i; m = length(p);
    for (i = m – 2; i >= 0; i--) {
        if (ch == p[i]) {
            return i;
        }
    }
    return -1;
}
