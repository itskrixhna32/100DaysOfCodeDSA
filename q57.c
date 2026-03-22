/*Problem Statement:
Check whether a given binary tree is symmetric around its center.
*/
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

int isMirror(struct Node* a, struct Node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;

    return (a->data == b->data) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);

    if (isMirror(root->left, root->right))
        printf("Symmetric\n");
    else
        printf("Not Symmetric\n");

    return 0;
}