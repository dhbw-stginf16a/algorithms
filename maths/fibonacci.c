int fib_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fib_recursive(n - 2) + fib_recursive(n - 1);
    }
}

int fib_iterative(int n) {
    int sum, k, i, j;
    i = 0;
    j = 1;
    for (k = 1; k <= n; k++) {
        sum = i + j;
        i = j;
        j = sum;
    }
    return j;
}
