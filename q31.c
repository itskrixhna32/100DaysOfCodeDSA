//Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

// Create new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Insert in descending order of power
struct Node* insert(struct Node* head, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);

    if (head == NULL || head->pow < pow) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->pow > pow) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Display polynomial
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Add two polynomials
struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            result = insert(result, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else if (p1->pow < p2->pow) {
            result = insert(result, p2->coeff, p2->pow);
            p2 = p2->next;
        }
        else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                result = insert(result, sum, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insert(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insert(result, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}

// Main function
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n, coeff, pow;

    printf("Enter number of terms in polynomial 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and power: ");
        scanf("%d %d", &coeff, &pow);
        poly1 = insert(poly1, coeff, pow);
    }

    printf("Enter number of terms in polynomial 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and power: ");
        scanf("%d %d", &coeff, &pow);
        poly2 = insert(poly2, coeff, pow);
    }

    printf("\nPolynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    result = addPoly(poly1, poly2);

    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}