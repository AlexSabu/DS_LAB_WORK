#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to find the least common ancestor
struct TreeNode* LCA(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    struct TreeNode* left = LCA(root->left, p, q);
    struct TreeNode* right = LCA(root->right, p, q);

    if (left && right) {
        return root;
    } else if (left) {
        return left;
    } else {
        return right;
    }
}

// Helper function to create a new binary tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Example usage
int main() {
    struct TreeNode* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    struct TreeNode* p = root->left;
    struct TreeNode* q = root->right;
    struct TreeNode* ancestor = LCA(root, p, q);
    printf("The least common ancestor of %d and %d is %d\n", p->val, q->val, ancestor->val);

    return 0;
}
