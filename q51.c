/*Problem: BST Search

Implement the solution for this problem.*/
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

struct Node* insert(struct Node* root, int x) {
    if (!root) return newNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (!root || root->data == key) return root;

    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);

    int key = 5;
    if (search(root, key))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}