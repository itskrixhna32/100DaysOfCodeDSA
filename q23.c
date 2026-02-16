/*Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers*/
#include <stdio.h>
#include <stdlib.h>

// structure of node
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp, *newnode;
    int n, value, count = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // create linked list
    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // count nodes
    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total number of nodes: %d ", count);

    return 0;
}