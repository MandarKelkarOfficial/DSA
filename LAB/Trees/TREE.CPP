#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Non-recursive preorder traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    struct Node* stack[100]; // Assuming a maximum of 100 nodes in the stack
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL) {
            stack[++top] = current->right;
        }

        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }

    printf("\n");
}

// Non-recursive display mirror image
void displayMirrorImage(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->left != NULL) {
            stack[++top] = current->left;
        }

        if (current->right != NULL) {
            stack[++top] = current->right;
        }
    }

    printf("\n");
}

// Non-recursive calculate height
int calculateHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    struct Node* stack[100];
    int top = -1;
    int height = 0;
    int maxDepth = 0;

    do {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
            height++;
        }

        if (height > maxDepth) {
            maxDepth = height;
        }

        if (top != -1) {
            root = stack[top--];
            root = root->right;
            height--;
        }
    } while (top != -1 || root != NULL);

    return maxDepth;
}

// Other utility functions for non-recursive operations

int main() {
    clrscr();

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int choice;
    do {
        printf("\nBinary Tree Operations Menu\n");
        printf("1. Preorder Traversal\n");
        printf("2. Display Mirror Image\n");
        printf("3. Display Height\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Preorder Traversal
                printf("Preorder Traversal:\n");
                preorderTraversal(root);
                break;
            case 2:
                // Display Mirror Image
                printf("Displaying Mirror Image:\n");
                displayMirrorImage(root);
                break;
            case 3:
                // Display Height
                printf("Height of the tree: %d\n", calculateHeight(root));
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    getch();
    return 0;
}
