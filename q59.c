//Problem Statement:
//Construct a binary tree from given preorder and inorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode *createNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to find index in inorder array
int findIndex(int inorder[], int start, int end, int val)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Recursive function to build tree
struct TreeNode *buildTreeHelper(int preorder[], int inorder[], int start, int end, int *preIndex)
{
    if (start > end)
        return NULL;

    // Pick current node from preorder
    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode *root = createNode(rootVal);

    // If leaf node
    if (start == end)
        return root;

    // Find index in inorder
    int inIndex = findIndex(inorder, start, end, rootVal);

    // Build left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTreeHelper(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Function to construct tree
struct TreeNode *buildTree(int preorder[], int inorder[], int n)
{
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, n - 1, &preIndex);
}

// Function to print inorder traversal (to verify tree)
void printInorder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

// Function to print preorder traversal (to verify tree)
void printPreorder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

// Main function
int main()
{
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int n = 5;

    struct TreeNode *root = buildTree(preorder, inorder, n);

    printf("Inorder traversal of constructed tree:\n");
    printInorder(root);

    printf("\nPreorder traversal of constructed tree:\n");
    printPreorder(root);

    return 0;
}