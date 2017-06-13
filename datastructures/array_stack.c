#include <stdlib.h>

/**
 * This is the template for any stack containing positive integers.
 */
struct stack {
    int s[100];
    /**
     * Size of the array
     */
    int size;
    /**
     * Top of the stack
     */
    int top;
}

void init(struct stack *stk) {
    stk->size = 100;  // max size of stack stk
    stk->top = 0;  // stack is initially empty
}

void push(struct stack *stk, int item) {
    if (stk->top < stk->size) {  // not full
        stk->s[stk->top] = item;
        stk->top++;
        return 1;  // true
    } else {
        return 0;  // false
    }
}

int pop(struct stack *stk) {
    if (stk->top > 0) {  // not empty
        stk->top--;
        return 1;  // true
    } else {
        return 0;  // false
    }
}

/**
 * Returns the top item or 0 if the stack is empty.
 * Renamed from `top` to `peek` which is more conventional.
 */
int peek(struct stack *stk) {
    if (stk->top > 0) {
        return stk->s[stk->top - 1];  // top item
    } else {
        return 0;  // false
    }
}
