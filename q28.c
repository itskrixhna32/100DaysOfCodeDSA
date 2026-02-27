/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

// Structure of linked list
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Count length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection point
int getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;
    struct Node *ptr1, *ptr2;

    if (len1 > len2) {
        diff = len1 - len2;
        ptr1 = head1;
        ptr2 = head2;
    } else {
        diff = len2 - len1;
        ptr1 = head2;
        ptr2 = head1;
    }

    // Move pointer of longer list
    for (int i = 0; i < diff; i++)
        ptr1 = ptr1->next;

    // Traverse together
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1->data;   // intersection data

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1; // No intersection
}

// Display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;

    // First linked list
    head1 = insertEnd(head1, 10);
    head1 = insertEnd(head1, 20);
    head1 = insertEnd(head1, 30);
    head1 = insertEnd(head1, 40);
    head1 = insertEnd(head1, 50);

    // Second linked list
    head2 = insertEnd(head2, 15);
    head2 = insertEnd(head2, 25);

    // Creating intersection manually
    struct Node* temp1 = head1;
    while (temp1->data != 30)
        temp1 = temp1->next;

    struct Node* temp2 = head2;
    while (temp2->next != NULL)
        temp2 = temp2->next;

    temp2->next = temp1; // intersection created

    printf("List 1: ");
    display(head1);

    printf("List 2: ");
    display(head2);

    int intersection = getIntersection(head1, head2);

    if (intersection == -1)
        printf("No intersection point\n");
    else
        printf("Intersection point data: %d\n", intersection);

    return 0;
}