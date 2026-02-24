//Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert node at end
struct Node *insertEnd(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to delete first occurrence of key
struct Node *deleteKey(struct Node *head, int key)
{
    struct Node *temp = head, *prev = NULL;

    // If head node itself holds key
    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        printf("First occurrence deleted.\n");
        return head;
    }

    // Search for key
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL)
    {
        printf("Key not found.\n");
        return head;
    }

    // Unlink node and free memory
    prev->next = temp->next;
    free(temp);
    printf("First occurrence deleted.\n");

    return head;
}

// Function to display list
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *head = NULL;
    int n, val, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    printf("Linked List: ");
    display(head);

    printf("Enter key to delete: ");
    scanf("%d", &key);

    head = deleteKey(head, key);

    printf("Updated List: ");
    display(head);

    return 0;
}