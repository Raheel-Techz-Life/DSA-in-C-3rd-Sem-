#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(&arr[minIdx], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("Sorting Algorithms Demo\n");
    printf("======================\n\n");
    
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    printf("Original array: ");
    printArray(arr1, n);
    
    bubbleSort(arr1, n);
    printf("After Bubble Sort: ");
    printArray(arr1, n);
    
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(arr2, n);
    printf("After Selection Sort: ");
    printArray(arr2, n);
    
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr3, n);
    printf("After Insertion Sort: ");
    printArray(arr3, n);
    
    return 0;
}
