struct node {
    int value;
    struct node *next;
}
typedef struct node *Nodepointer;

struct stack {
    Nodepointer top;
}
typedef struct stack *Stackpointer;

int push(Stackpointer stack, int item) {
    Nodepointer new = (Nodepointer) malloc(sizeof(struct node));

    if (new != NULL) {  // not full
        new->value = item;
        new->next = stack->top;
        stack->top = new;
        return 1;  // true
    } else {
        return 0;  // false
    }
}

int pop(Stackpointer stack) {
    if (stack->top != NULL) {  // not empty
        stack->top = stack->top->next;
        // TODO free missing?
        return 1;  // true
    } else {
        return 0;  // false
    }
}

/**
 * Renamed top to peek which is more common.
 */
int peek(Stackpointer stack) {
    if (stack->top != NULL) {  // not empty
        return stack->top->value;  // top item
    } else {
        return 0;  // false
    }
}

Stackpointer init() {
    Stackpointer stack = (Stackpointer) malloc(sizeof (struct stack));
    stack->top = NULL;
    return stack;
}
