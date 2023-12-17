#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to traverse the binary tree in Postorder (non-recursive)
void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Create two stacks for Postorder traversal
    TreeNode* stack1[100];
    TreeNode* stack2[100];
    int top1 = -1;
    int top2 = -1;

    // Push the root onto the first stack
    stack1[++top1] = root;

    // Process nodes in the first stack and push them onto the second stack
    while (top1 != -1) {
        // Pop a node from the first stack
        TreeNode* current = stack1[top1--];

        // Push the node onto the second stack
        stack2[++top2] = current;

        // Push the left and right children onto the first stack
        if (current->left != NULL) {
            stack1[++top1] = current->left;
        }
        if (current->right != NULL) {
            stack1[++top1] = current->right;
        }
    }

    // Display nodes from the second stack (Postorder sequence)
    while (top2 != -1) {
        printf("%c ", stack2[top2--]->data);
    }
}

int main() {
    // Generate the binary tree
    TreeNode* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('F');
    root->left->left = createNode('D');
    root->left->right = createNode('C');
    root->left->right->left = createNode('E');
    root->right->right = createNode('H');
    root->right->right->left = createNode('K');
    root->right->right->right = createNode('G');

    // Display Postorder traversal
    printf("Postorder Traversal: ");
    postorderTraversal(root);

    // Clean up allocated memory
    // (Note: A complete program should have proper memory deallocation)
    free(root->left->left);
    free(root->left->right->left);
    free(root->left->right);
    free(root->left);
    free(root->right->right->left);
    free(root->right->right->right);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}
