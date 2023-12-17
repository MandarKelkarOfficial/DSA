#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

// Structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Node* current = *root;
    struct Node* parent = NULL;
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

// Function to perform inorder traversal non-recursively
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function to create a mirror image of the binary tree
struct Node* createMirrorTree(struct Node* root) {
    if (root == NULL) return NULL;

    struct Node* mirror = createNode(root->data);
    mirror->left = createMirrorTree(root->right);
    mirror->right = createMirrorTree(root->left);

    return mirror;
}

// Function to check the equality of two trees
bool areTreesEqual(struct Node* tree1, struct Node* tree2) {
    if (tree1 == NULL && tree2 == NULL) return true;
    if (tree1 == NULL || tree2 == NULL) return false;

    return (tree1->data == tree2->data) &&
           areTreesEqual(tree1->left, tree2->left) &&
           areTreesEqual(tree1->right, tree2->right);
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    struct Node* mirrorTree = NULL;

    while (1) {
        printf("\nBinary Tree Menu:\n");
        printf("1. Insert a node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Display mirror image of the tree\n");
        printf("4. Check equality of two trees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                mirrorTree = createMirrorTree(root);
                printf("Mirror Image of the Tree (Inorder Traversal): ");
                inorderTraversal(mirrorTree);
                printf("\n");
                break;
            case 4:
                if (root == NULL || mirrorTree == NULL) {
                    printf("Both trees are not available for comparison.\n");
                } else {
                    if (areTreesEqual(root, mirrorTree)) {
                        printf("The original tree and its mirror image are equal.\n");
                    } else {
                        printf("The original tree and its mirror image are not equal.\n");
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
