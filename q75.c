// Day 75 Question 1: Largest Subarray with Zero Sum
// Find the length of the largest subarray with sum equal to 0

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int sum;
    int index;
} HashNode;

int largestSubarrayWithZeroSum(int arr[], int n) {
    HashNode* hashTable = (HashNode*)calloc(2 * MAX + 1, sizeof(HashNode));
    int maxLen = 0;
    int sum = 0;
    
    // Initialize hash table
    for (int i = 0; i < 2 * MAX + 1; i++) {
        hashTable[i].index = -1;
    }
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        
        // If sum is 0, subarray from 0 to i has zero sum
        if (sum == 0) {
            maxLen = i + 1;
        }
        
        // Check if this sum was seen before
        int hashIndex = sum + MAX;
        if (hashTable[hashIndex].index != -1) {
            int len = i - hashTable[hashIndex].index;
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            hashTable[hashIndex].sum = sum;
            hashTable[hashIndex].index = i;
        }
    }
    
    free(hashTable);
    return maxLen;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result = largestSubarrayWithZeroSum(arr, n);
    printf("Length of largest subarray with zero sum: %d\n", result);
    
    return 0;
}
