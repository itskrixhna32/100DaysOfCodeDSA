/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

// Function to create list
struct node *createList(int n)
{
    struct node *head = NULL, *temp, *newnode;
    int value;

    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

// Function to merge lists
struct node *merge(struct node *l1, struct node *l2)
{
    struct node *head = NULL, *temp = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));

        if (l1->data < l2->data)
        {
            newnode->data = l1->data;
            l1 = l1->next;
        }
        else
        {
            newnode->data = l2->data;
            l2 = l2->next;
        }

        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // remaining elements
    while (l1 != NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = l1->data;
        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        l1 = l1->next;
    }

    while (l2 != NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = l2->data;
        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        l2 = l2->next;
    }

    return head;
}

// Display list
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    int n1, n2;

    printf("Enter number of nodes in first sorted list: ");
    scanf("%d", &n1);
    printf("Enter elements (sorted): ");
    struct node *list1 = createList(n1);

    printf("Enter number of nodes in second sorted list: ");
    scanf("%d", &n2);
    printf("Enter elements (sorted): ");
    struct node *list2 = createList(n2);

    struct node *merged = merge(list1, list2);

    printf("Merged Sorted List:\n");
    display(merged);

    return 0;
}