//Problem Statement: Given a queue of integers, reverse the queue using a stack.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1;
int queue[MAX], front = 0, rear = 0;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

void reverseQueue() {
    while (front < rear)
        push(queue[front++]);

    while (top != -1)
        queue[rear++] = pop();
}