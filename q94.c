// Day 94 Question 1: Counting Sort Implementation
// Sort an array using Counting Sort algorithm

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    // Find maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Create count array
    int* count = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));
    
    // Store count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Change count[i] to contain actual position
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    // Copy output array to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    free(count);
    free(output);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter array elements (non-negative): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: ");
    printArray(arr, n);
    
    countingSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
