//Problem Statement:
//Implement a Queue using a linked list supporting enqueue and dequeue operations.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL)
        front = rear = temp;
    else {
        rear->next = temp;
        rear = temp;
    }
}

int dequeue() {
    struct Node* temp = front;
    int x = temp->data;
    front = front->next;
    free(temp);
    return x;
}