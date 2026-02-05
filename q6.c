/*Problem:A system receives two separate logs of user arrival times from two different servers. 
Each log is already sorted in ascending order. 
Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)*/

#include <stdio.h>
#define MAX_SIZE 1000
void merge_logs(int log1[], int size1, int log2[], int size2, int merged_log[]) {
    int i = 0, j = 0, k = 0;

    // Merge the two logs
    while (i < size1 && j < size2) {
        if (log1[i] <= log2[j]) {
            merged_log[k++] = log1[i++];
        } else {
            merged_log[k++] = log2[j++];
        }
    }

    // Copy remaining elements from log1, if any
    while (i < size1) {
        merged_log[k++] = log1[i++];
    }

    // Copy remaining elements from log2, if any
    while (j < size2) {
        merged_log[k++] = log2[j++];
    }
}
int main() {
    int p, q;
    int log1[MAX_SIZE], log2[MAX_SIZE], merged_log[2 * MAX_SIZE];

    // Read size and elements of first log
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    // Read size and elements of second log
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    // Merge the two logs
    merge_logs(log1, p, log2, q, merged_log);

    // Print the merged log
    for (int i = 0; i < p + q; i++) {
        printf("%d ", merged_log[i]);
    }
    printf("\n");

    return 0;
}