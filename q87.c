// Day 87 Question 1: Implement Binary Search Iterative
// Implement iterative binary search algorithm

#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
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
    
    return -1; // Element not found
}

int main() {
    int n, target;
    printf("Enter size of sorted array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter sorted array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter target value: ");
    scanf("%d", &target);
    
    int result = binarySearch(arr, n, target);
    
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}
