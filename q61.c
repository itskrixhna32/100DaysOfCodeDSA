#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Count total nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if complete binary tree
int isComplete(struct Node* root, int index, int node_count) {
    if (root == NULL)
        return 1;

    if (index >= node_count)
        return 0;

    return isComplete(root->left, 2 * index + 1, node_count) &&
           isComplete(root->right, 2 * index + 2, node_count);
}

// Check Min-Heap property
int isHeapUtil(struct Node* root) {
    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Only left child
    if (root->right == NULL) {
        return (root->data <= root->left->data) &&
               isHeapUtil(root->left);
    }

    // Both children exist
    if (root->data <= root->left->data &&
        root->data <= root->right->data)
        return isHeapUtil(root->left) &&
               isHeapUtil(root->right);

    return 0;
}

// Main function to check Min Heap
int isHeap(struct Node* root) {
    int node_count = countNodes(root);
    if (isComplete(root, 0, node_count) && isHeapUtil(root))
        return 1;
    return 0;
}

// Example usage
int main() {
    struct Node* root = newNode(10);
    root->left = newNode(15);
    root->right = newNode(20);
    root->left->left = newNode(30);
    root->left->right = newNode(40);

    if (isHeap(root))
        printf("The binary tree is a Min Heap\n");
    else
        printf("The binary tree is NOT a Min Heap\n");

    return 0;
}