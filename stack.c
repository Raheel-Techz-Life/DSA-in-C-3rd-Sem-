#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to create a stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->items[++stack->top] = item;
    printf("Pushed %d to stack\n", item);
}

// Function to pop an element
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Function to peek at the top element
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->items[stack->top];
}

// Function to display stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack* stack = createStack();
    
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    
    display(stack);
    
    printf("Top element: %d\n", peek(stack));
    printf("Popped: %d\n", pop(stack));
    
    display(stack);
    
    free(stack);
    return 0;
}
