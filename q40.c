//Problem Statement: Implement a Min Heap using an array where the smallest element is always at the root.
#include <stdio.h>

int heap[100], size = 0;

void insert(int x) {
    int i = size++;
    heap[i] = x;

    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        int t = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = t;
        i = (i - 1) / 2;
    }
}