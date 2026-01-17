#include <stdio.h>

#define MAX_SIZE 100

// Function to traverse and display array elements
void traverse(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position
int insert(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array is full!\n");
        return 0;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return 0;
    }
    
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
    return 1;
}

// Function to delete an element at a specific position
int delete(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Array is empty!\n");
        return 0;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return 0;
    }
    
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    return 1;
}

// Function to search for an element
int search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE] = {10, 20, 30, 40, 50};
    int size = 5;
    
    printf("Initial array:\n");
    traverse(arr, size);
    
    // Insert operation
    insert(arr, &size, 25, 2);
    printf("\nAfter inserting 25 at position 2:\n");
    traverse(arr, size);
    
    // Search operation
    int pos = search(arr, size, 30);
    if (pos != -1) {
        printf("\nElement 30 found at position: %d\n", pos);
    }
    
    // Delete operation
    delete(arr, &size, 3);
    printf("\nAfter deleting element at position 3:\n");
    traverse(arr, size);
    
    return 0;
}
