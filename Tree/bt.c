#include <stdio.h>
#include <stdlib.h>

// Define a binary tree node
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to generate binary tree from Inorder and Preorder traversals
struct TreeNode* buildTree(char inorder[], char preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    // Create the root node
    struct TreeNode* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    // Find the index of the root in Inorder traversal
    int inIndex;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->data) {
            inIndex = i;
            break;
        }
    }

    // Recursively build the left and right subtrees
    root->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Function to traverse the tree in Postorder (non-recursive)
void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Two stacks for simulating Postorder traversal
    struct TreeNode* stack1[100];
    struct TreeNode* stack2[100];
    int top1 = -1;
    int top2 = -1;

    // Push the root onto the first stack
    stack1[++top1] = root;

    while (top1 >= 0) {
        // Pop a node from the first stack
        struct TreeNode* temp = stack1[top1--];

        // Push the popped node to the second stack
        stack2[++top2] = temp;

        // Push left and right children of the popped node to the first stack
        if (temp->left) {
            stack1[++top1] = temp->left;
        }
        if (temp->right) {
            stack1[++top1] = temp->right;
        }
    }

    // Print nodes from the second stack (Postorder)
    while (top2 >= 0) {
        printf("%c ", stack2[top2--]->data);
    }
}

// Example usage
int main() {
    char inorder[] = {'B', 'D', 'C', 'E', 'A', 'H', 'K', 'F', 'G'};
    char preorder[] = {'A', 'B', 'C', 'D', 'E', 'F', 'H', 'K', 'G'};
    int preIndex = 0;

    // Build the binary tree
    struct TreeNode* root = buildTree(inorder, preorder, 0, sizeof(inorder) / sizeof(inorder[0]) - 1, &preIndex);

    // Traverse the tree in Postorder (non-recursive) and display the sequence
    printf("Postorder Traversal: ");
    postorderTraversal(root);

    return 0;
}
