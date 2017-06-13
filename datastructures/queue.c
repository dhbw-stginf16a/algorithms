/**
 * This is the template for any queue containing positive integers.
 */
stuct queue {
    int q[100];
    int size;
    int front;
    int rear;
}

void init(struct queue *qu) {
    qu->size = 100;  // max size of the queue
    qu->front = 0;  // queue is initially empty
    qu->rear = -1;
}

