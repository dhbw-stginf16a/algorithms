#include "queue.h"

int insert(struct queue *qu, int item) {
    if (qu->rear < qu->size - 1) {  // not full
        qu->rear++;
        qu->q[qu->rear] = item;
        return 1;  // true
    } else {
        return 0;  // false
    }
}

int delete(struct queue *qu) {
    if (qu->front <= qu->rear) {  // not empty
        qu->front++;
        return 1;  // true
    } else {
        return 0;  // false
    }
}

int first(struct queue *qu) {
    if (qu->front <= qu->rear) {  // not empty
        return qu->q[qu->front];  // first item
    } else {
        return 0;  // false
    }
}
