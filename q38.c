//Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

#include <stdio.h>
#define MAX 100

int pq[MAX], n = 0;

void insert(int x) {
    int i = n - 1;
    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = x;
    n++;
}

int deleteMin() {
    if (n == 0) return -1;
    return pq[--n];
}

int main() {
    insert(5); insert(2); insert(8);
    printf("%d\n", deleteMin());
}