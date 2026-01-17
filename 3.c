#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int stack[MAX];
int top = -1;

void push() {
    int item;
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter element to be inserted\n");
    scanf("%d", &item);
    stack[++top] = item;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Deleted element is %d\n", stack[top--]);
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void palindrome() {
    int i, flag = 1;
    for (i = 0; i <= top / 2; i++) {
        if (stack[i] != stack[top - i]) {
            flag = 0;
            break;
        }
    }
    if (top == -1)
        printf("Stack is empty\n");
    else if (flag)
        printf("Stack contents form a palindrome\n");
    else
        printf("Stack contents do not form a palindrome\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Palindrome\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: palindrome(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
