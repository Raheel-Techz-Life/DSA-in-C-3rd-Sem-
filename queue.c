#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue structure
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if queue is full
int isFull(struct Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Function to check if queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue Overflow!\n");
        return;
    }
    
    if (queue->front == -1) {
        queue->front = 0;
    }
    
    queue->items[++queue->rear] = item;
    printf("Enqueued %d\n", item);
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    
    int item = queue->items[queue->front++];
    
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    
    return item;
}

// Function to display queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    
    display(queue);
    
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    
    display(queue);
    
    return 0;
}
