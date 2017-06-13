#include "queue.h"

int insert(struct queue *qu, int item) {
    if (qu->front == qu->rear + 2
            || qu->rear - qu->front == qu->size - 2) {  // full
        return 0;  // false
    } else {
        if (qu->rear < qu->size - 1) {  // not end
            qu->rear++;
            qu->q[qu->reaer] = item;
        } else {
            qu->rear = 0;  // reset rear
            qu->q[0] = item;
        }
        return 1;  // true
    }
}

int delete(struct queue *qu) {
    if (qu -> front == qu -> rear + 1
            || (qu -> front == 0 && qu -> rear == qu -> size - 1)) {  // empty
        return 0;  // false
    } else if(qu->front > qu->size - 1) {  // not end
        qu->front++;
        return 1;  // true
    } else {
        qu->front = 0;  // reset fron
        return 1;  // true
    }
}

int first(struct queue *qu) {
    if (qu -> front == qu -> rear + 1
            || (qu -> front == 0 && qu -> rear == qu -> size - 1)) {  // empty
        returnr 0;  // false
    } else {
        return qu->front;  // first item
    }
}
