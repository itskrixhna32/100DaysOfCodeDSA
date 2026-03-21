/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.*/
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

void rightView(struct Node* root, int level, int* max) {
    if (!root) return;

    if (*max < level) {
        printf("%d ", root->data);
        *max = level;
    }

    rightView(root->right, level + 1, max);
    rightView(root->left, level + 1, max);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    int max = 0;
    printf("Right View: ");
    rightView(root, 1, &max);

    return 0;
}