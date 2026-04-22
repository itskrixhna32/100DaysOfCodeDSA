// Day 88 Question 1: Aggressive Cows Problem
// Place cows in stalls to maximize minimum distance between them

#include <stdio.h>
#include <stdbool.h>

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

bool canPlaceCows(int stalls[], int n, int cows, int minDist) {
    int count = 1;
    int lastPos = stalls[0];
    
    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
            if (count == cows) {
                return true;
            }
        }
    }
    
    return false;
}

int aggressiveCows(int stalls[], int n, int cows) {
    bubbleSort(stalls, n);
    
    int left = 1;
    int right = stalls[n - 1] - stalls[0];
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canPlaceCows(stalls, n, cows, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    int n, cows;
    printf("Enter number of stalls: ");
    scanf("%d", &n);
    
    int stalls[n];
    printf("Enter stall positions: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }
    
    printf("Enter number of cows: ");
    scanf("%d", &cows);
    
    int result = aggressiveCows(stalls, n, cows);
    printf("Maximum minimum distance: %d\n", result);
    
    return 0;
}
