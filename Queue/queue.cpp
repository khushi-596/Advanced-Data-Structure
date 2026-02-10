#include "queue.h"

Queue::Queue() {
    front = -1;
    rear = -1;
}

bool Queue::isEmpty() {
    return front == -1 || front > rear;
}

bool Queue::isFull() {
    return rear == MAX - 1;
}

void Queue::enqueue(int data) {
    if (!isFull()) {
        if (front == -1)
            front = 0;
        arr[++rear] = data;
    }
}

int Queue::dequeue() {
    if (!isEmpty()) {
        return arr[front++];
    }
    return -1;   
}

