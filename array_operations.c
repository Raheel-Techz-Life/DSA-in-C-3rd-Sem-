#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertElement(int arr[], int size, int element, int position) {
    if (size >= MAX_SIZE) {
        printf("Array is full\n");
        return size;
    }
    if (position < 0 || position > size) {
        printf("Invalid position\n");
        return size;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    return size + 1;
}

int deleteElement(int arr[], int size, int position) {
    if (size <= 0) {
        printf("Array is empty\n");
        return size;
    }
    if (position < 0 || position >= size) {
        printf("Invalid position\n");
        return size;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

int main() {
    int arr[MAX_SIZE] = {10, 20, 30, 40, 50};
    int size = 5;
    
    printf("Array Operations Demo\n");
    printf("===================\n\n");
    
    displayArray(arr, size);
    
    size = insertElement(arr, size, 25, 2);
    printf("After inserting 25 at position 2:\n");
    displayArray(arr, size);
    
    size = deleteElement(arr, size, 3);
    printf("After deleting element at position 3:\n");
    displayArray(arr, size);
    
    return 0;
}
