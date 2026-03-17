/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.*/
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

struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    return root;
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);

    struct Node* res = LCA(root, 5, 15);
    printf("LCA: %d\n", res->data);

    return 0;
}