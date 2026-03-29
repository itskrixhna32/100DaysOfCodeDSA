/*Problem Statement:
Find the height (maximum depth) of a given binary tree.
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

int height(struct Node* root) {
    if (!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);

    printf("Height: %d", height(root));
    return 0;
}