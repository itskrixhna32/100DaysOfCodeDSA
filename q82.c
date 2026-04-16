// Day 82 Question 1: Upper Bound & Lower Bound Implementation
// Implement lower bound and upper bound using binary search

#include <stdio.h>

// Lower bound: first position where element >= target
int lowerBound(int arr[], int n, int target) {
    int left = 0, right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

// Upper bound: first position where element > target
int upperBound(int arr[], int n, int target) {
    int left = 0, right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
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
    
    int lb = lowerBound(arr, n, target);
    int ub = upperBound(arr, n, target);
    
    printf("Lower bound of %d: %d\n", target, lb);
    printf("Upper bound of %d: %d\n", target, ub);
    
    if (lb < n) {
        printf("Element at lower bound: %d\n", arr[lb]);
    }
    if (ub < n) {
        printf("Element at upper bound: %d\n", arr[ub]);
    }
    
    return 0;
}
