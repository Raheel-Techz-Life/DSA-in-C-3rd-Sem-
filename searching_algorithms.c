#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] > key) {
            return binarySearchRecursive(arr, low, mid - 1, key);
        }
        return binarySearchRecursive(arr, mid + 1, high, key);
    }
    return -1;
}

int main() {
    printf("Searching Algorithms Demo\n");
    printf("========================\n\n");
    
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = 9;
    int key = 50;
    
    int result = linearSearch(arr, n, key);
    if (result != -1) {
        printf("Linear Search: Element %d found at index %d\n", key, result);
    } else {
        printf("Linear Search: Element %d not found\n", key);
    }
    
    result = binarySearch(arr, 0, n - 1, key);
    if (result != -1) {
        printf("Binary Search (Iterative): Element %d found at index %d\n", key, result);
    } else {
        printf("Binary Search (Iterative): Element %d not found\n", key);
    }
    
    result = binarySearchRecursive(arr, 0, n - 1, key);
    if (result != -1) {
        printf("Binary Search (Recursive): Element %d found at index %d\n", key, result);
    } else {
        printf("Binary Search (Recursive): Element %d not found\n", key);
    }
    
    return 0;
}
