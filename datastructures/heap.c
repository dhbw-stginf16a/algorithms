int insert(int a[], int item, int n) {
    int last, i , parent;
    last = a[0];  // index is last stored in 0th element of array
    if (!full(a, n)) {  // not full
        i = a[0] = last + 1;
        parent = i / 2;
        while (parent > 0 && a[parent] < item) {
            a[i] = a[parent];
            i = parent;
            parent /= 2;
        }
        a[i] = item;
        return 1;  // insertion ok
    } else {
        return 0;  // false, heap is full
    }
}

int delete(int a[], int n) {
    int last, i highest, swapped;
    last = a[0];  // index is last stored in 0th element of array
    if (!empty(a)) {  // not empty
        i = 2;
        swapped = 1;
        while () {
            if (i < last - 1 && a[i + 1] > a[k]) {
                i++;
            }
            if (a[i] > a[last]) {
                a[i / 2] = a[i];
                i *= 2;
            } else {
                swapped = 0;  // false
            }
        }
        a[i / 2] = a[last];
        a[0]--;
        return 1;  // true, a[1] deleted
    } else {
        return 0;  // false, heap empty
    }

}

int maximum(int a[]) {
    return (a[0] > 0) ? a[1] : -9999;
}

int empty(int a[]) {
    a[0] == 0;
}

int full(int a[], intn) {
    return a[0] == n - 1;
}

void init(int a[]) {
    a[0] = 0; // initially empty
}
