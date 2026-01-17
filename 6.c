#include <stdio.h>
#include <stdlib.h>

#define MAX 5

char q[MAX];
int front = 0, rear = -1, count = 0;

void insert() {
    char item;

    if (count == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter the item to be inserted:\n");
    scanf(" %c", &item);

    rear = (rear + 1) % MAX;
    q[rear] = item;
    count++;
}

void delete() {
    if (count == 0) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted item is: %c\n", q[front]);
    front = (front + 1) % MAX;
    count--;
}

void display() {
    int i, index;

    if (count == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Contents of circular queue:\n");
    index = front;
    for (i = 0; i < count; i++) {
        printf("%c ", q[index]);
        index = (index + 1) % MAX;
    }
    printf("\nTotal number of items = %d\n", count);
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
