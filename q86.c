// Day 86 Question 1: Square Root using Binary Search
// Find square root of a number using binary search

#include <stdio.h>

int sqrtBinarySearch(int x) {
    if (x == 0 || x == 1) {
        return x;
    }
    
    int left = 1, right = x, result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if mid is perfect square
        if (mid == x / mid) {
            return mid;
        }
        
        // If mid*mid < x, search in right half
        if (mid < x / mid) {
            left = mid + 1;
            result = mid;
        } else {
            // Search in left half
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    
    int result = sqrtBinarySearch(x);
    printf("Square root of %d is: %d\n", x, result);
    
    return 0;
}
