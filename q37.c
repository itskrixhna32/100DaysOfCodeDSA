//Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;

    if (front == NULL) {
        front = rear = temp;
        rear->next = front;   // circular link
    } else {
        rear->next = temp;
        rear = temp;
        rear->next = front;   // maintain circular
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return -1;
    }

    int val = front->data;

    // Only one node
    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        front = front->next;
        rear->next = front;   // maintain circular
        free(temp);
    }

    return val;
}

void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node* temp = front;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Deleted: %d\n", dequeue());
    display();

    return 0;
}