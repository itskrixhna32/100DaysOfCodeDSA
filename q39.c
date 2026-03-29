/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear.
It provides more flexibility than a standard queue or stack.*/
#include <stdio.h>
#define MAX 100

int dq[MAX], front = -1, rear = -1;

void insertFront(int x) {
    if (front == -1) front = rear = 0;
    else front--;
    dq[front] = x;
}

void insertRear(int x) {
    if (rear == -1) front = rear = 0;
    else rear++;
    dq[rear] = x;
}

int deleteFront() {
    return dq[front++];
}

int deleteRear() {
    return dq[rear--];
}