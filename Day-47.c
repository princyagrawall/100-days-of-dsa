#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate height of binary tree
int height(struct TreeNode* root) {
    // Base case
    if (root == NULL)
        return 0;

    // Recursive calls
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Return max + 1
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Example usage
int main() {
    /*
            1
           / \
          2   3
         /
        4
    */

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    printf("Height of tree: %d\n", height(root));

    return 0;
}