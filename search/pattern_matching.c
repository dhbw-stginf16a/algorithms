#include <stdlib.h>
#include <string.h>

int find(char p[], char ch);

/**
 * @param char s[] source string
 * @param char p[] pattern
 */
int bruteforce_match(char s[], char p[]) {
    int n = strlen(s);
    int m = strlen(p);
    for (int i = 0; i <= n - m; i++) {  // for each pattern comparison
        int j = 0;
        while (j < m && s[i+j] == p[j]) {  // each character comparison
            j++;
        }  // end while
        if (j == m) {
            return i;
        } else {
            return -1;  // not matched
        }
    }
}

/**
 * @param char s[] source string
 * @param char p[] pattern
 */
int boyermoore_match(char s[], char p[]) {
    int lastch;
    int n = strlen(s);
    int m = strlen(p);
    int i = m - 1;
    int j = m - 1;
    while (i < n) {  // not end of string s
        if (p[j] == s[i]) {
            if (j == 0) {  // first char of pattern
                return i;
            } else {
                // go left
                j--;
                i--;
            }
        } else {  // no match – find char in pattern
            lastch = find(p, s[i]);
            if (lastch == -1) {  // not found
                i = i + m;  // jump over
            } else {
                i = i + j - lastch; // align char
            }
            j = m - 1;  // restart from right
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
    int m = strlen(p);
    for (int i = m - 2; i >= 0; i--) {
        if (ch == p[i]) {
            return i;
        }
    }
    return -1;
}
