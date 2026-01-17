#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    
    *head = newNode;
}

// Function to insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display forward
void displayForward(struct Node* head) {
    printf("Forward: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to display backward
void displayBackward(struct Node* head) {
    if (head == NULL) return;
    
    // Go to the last node
    while (head->next != NULL) {
        head = head->next;
    }
    
    printf("Backward: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    
    displayForward(head);
    displayBackward(head);
    
    return 0;
}
