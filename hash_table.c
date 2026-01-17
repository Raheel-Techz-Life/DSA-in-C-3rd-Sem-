#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

struct Node {
    int key;
    int value;
    struct Node* next;
};

struct Node* hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

void insert(int key, int value) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    printf("Inserted key %d with value %d at index %d\n", key, value, index);
}

int search(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

void display() {
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("[%d:%d] -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    printf("Hash Table Demo\n");
    printf("==============\n\n");
    
    initHashTable();
    
    insert(5, 100);
    insert(15, 200);
    insert(25, 300);
    insert(7, 400);
    
    display();
    
    int key = 15;
    int value = search(key);
    if (value != -1) {
        printf("\nValue for key %d: %d\n", key, value);
    } else {
        printf("\nKey %d not found\n", key);
    }
    
    return 0;
}
