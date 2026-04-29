// Day 95 Question 1: Bucket Sort (Float Values 0–1)
// Sort an array of float values between 0 and 1 using Bucket Sort

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float data;
    struct Node* next;
} Node;

void insertSorted(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void bucketSort(float arr[], int n) {
    // Create n empty buckets
    Node** buckets = (Node**)calloc(n, sizeof(Node*));
    
    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        insertSorted(&buckets[bucketIndex], arr[i]);
    }
    
    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    free(buckets);
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    float arr[n];
    printf("Enter array elements (between 0 and 1): ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    
    printf("Original array: ");
    printArray(arr, n);
    
    bucketSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
