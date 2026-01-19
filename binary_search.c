#include <stdio.h>

// Iterative binary search function
int binarySearchIterative(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

// Recursive binary search function
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    }
    
    if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, right, target);
    } else {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Iterative search
    int result = binarySearchIterative(arr, size, target);
    if (result != -1) {
        printf("\nIterative: Element %d found at index %d\n", target, result);
    } else {
        printf("\nIterative: Element %d not found\n", target);
    }
    
    // Recursive search
    result = binarySearchRecursive(arr, 0, size - 1, target);
    if (result != -1) {
        printf("Recursive: Element %d found at index %d\n", target, result);
    } else {
        printf("Recursive: Element %d not found\n", target);
    }
    
    return 0;
}
