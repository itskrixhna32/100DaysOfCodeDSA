// Day 98 Question 1: Merge Overlapping Intervals
// Merge all overlapping intervals

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

void swap(Interval* a, Interval* b) {
    Interval temp = *a;
    *a = *b;
    *b = temp;
}

void sortIntervals(Interval intervals[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (intervals[j].start > intervals[j + 1].start) {
                swap(&intervals[j], &intervals[j + 1]);
            }
        }
    }
}

int mergeIntervals(Interval intervals[], int n, Interval result[]) {
    if (n == 0) {
        return 0;
    }
    
    sortIntervals(intervals, n);
    
    int index = 0;
    result[index] = intervals[0];
    
    for (int i = 1; i < n; i++) {
        if (result[index].end >= intervals[i].start) {
            // Merge intervals
            if (intervals[i].end > result[index].end) {
                result[index].end = intervals[i].end;
            }
        } else {
            // No overlap, add new interval
            index++;
            result[index] = intervals[i];
        }
    }
    
    return index + 1;
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);
    
    Interval intervals[n];
    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }
    
    Interval result[n];
    int resultSize = mergeIntervals(intervals, n, result);
    
    printf("Merged intervals:\n");
    for (int i = 0; i < resultSize; i++) {
        printf("[%d, %d]\n", result[i].start, result[i].end);
    }
    
    return 0;
}
