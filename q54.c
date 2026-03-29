/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue Node (for BFS)
struct QNode {
    struct Node* node;
    int hd; // horizontal distance
};

// Create new tree node
struct Node* newNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// Function for Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QNode queue[MAX];
    int front = 0, rear = 0;

    // To store results (HD range -50 to +50)
    int result[100][100];
    int count[100] = {0};

    // offset for negative HD
    int offset = 50;

    // push root
    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd + offset;

        // store node
        result[hd][count[hd]++] = curr->data;

        // left child
        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, temp.hd - 1};

        // right child
        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, temp.hd + 1};
    }

    // print result
    printf("Vertical Order Traversal:\n");
    for (int i = 0; i < 100; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
}

// Driver code
int main() {

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    verticalOrder(root);

    return 0;
}