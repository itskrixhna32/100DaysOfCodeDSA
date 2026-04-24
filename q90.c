// Day 90 Question 1: Painter Partition Problem
// Allocate boards to painters to minimize maximum time

#include <stdio.h>
#include <stdbool.h>

bool isPossible(int boards[], int n, int painters, int maxTime) {
    int painterCount = 1;
    int currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) {
            return false;
        }
        
        if (currentTime + boards[i] > maxTime) {
            painterCount++;
            currentTime = boards[i];
            
            if (painterCount > painters) {
                return false;
            }
        } else {
            currentTime += boards[i];
        }
    }
    
    return true;
}

int painterPartition(int boards[], int n, int painters) {
    int sum = 0, maxBoard = 0;
    for (int i = 0; i < n; i++) {
        sum += boards[i];
        if (boards[i] > maxBoard) {
            maxBoard = boards[i];
        }
    }
    
    int left = maxBoard, right = sum;
    int result = sum;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (isPossible(boards, n, painters, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {
    int n, painters;
    printf("Enter number of boards: ");
    scanf("%d", &n);
    
    int boards[n];
    printf("Enter length of each board: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }
    
    printf("Enter number of painters: ");
    scanf("%d", &painters);
    
    int result = painterPartition(boards, n, painters);
    printf("Minimum time to paint all boards: %d\n", result);
    
    return 0;
}
