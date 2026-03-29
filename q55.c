//Problem Statement:
//Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

void zigzag(struct Node* root) {
    if (!root) return;

    struct Node* queue[100];
    int front = 0, rear = 0;
    int leftToRight = 1;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* temp = queue[front++];
            printf("%d ", temp->data);

            if (temp->left) queue[rear++] = temp->left;
            if (temp->right) queue[rear++] = temp->right;
        }
        leftToRight = !leftToRight;
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    printf("Zigzag: ");
    zigzag(root);

    return 0;
}