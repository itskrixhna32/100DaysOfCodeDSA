//Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create circular linked list
struct Node* create(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;

    if (n <= 0) return NULL;

    for (int i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
            newNode->next = head; // circular link
        } else {
            temp->next = newNode;
            newNode->next = head; // maintain circular nature
            temp = newNode;
        }
    }
    return head;
}

// Function to traverse circular linked list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// Main function
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node* head = create(n);

    printf("Circular Linked List: ");
    traverse(head);

    return 0;
}