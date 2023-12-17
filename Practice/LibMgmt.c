#include <stdio.h>
#include <stdlib.h>

// Maximum number of books in the library
#define MAX_BOOKS 100

// Structure to represent a book
struct Book {
    char title[100];
    char author[100];
    int bookID;
    int isIssued; // 0 for not issued, 1 for issued
};

// Array to store books in the library
struct Book library[MAX_BOOKS];

// Current number of books in the library
int numBooks = 0;

void addBook() {
    if (numBooks >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter the title of the book: ");
    scanf(" %[^\n]", library[numBooks].title);
    
    printf("Enter the author of the book: ");
    scanf(" %[^\n]", library[numBooks].author);
    
    printf("Enter the book ID: ");
    scanf("%d", &library[numBooks].bookID);

    library[numBooks].isIssued = 0;
    numBooks++;

    printf("Book added successfully.\n");
}

void removeBook() {
    int bookID, i, found = 0;
    printf("Enter the book ID to remove: ");
    scanf("%d", &bookID);

    for (i = 0; i < numBooks; i++) {
        if (library[i].bookID == bookID) {
            found = 1;
            // Shift books after the one to be removed
            for (; i < numBooks - 1; i++) {
                library[i] = library[i + 1];
            }
            numBooks--;
            printf("Book removed successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found in the library.\n", bookID);
    }
}

void issueBook() {
    int bookID, i, found = 0;
    printf("Enter the book ID to issue: ");
    scanf("%d", &bookID);

    for (i = 0; i < numBooks; i++) {
        if (library[i].bookID == bookID) {
            found = 1;
            if (library[i].isIssued) {
                printf("Book is already issued.\n");
            } else {
                library[i].isIssued = 1;
                printf("Book issued successfully.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found in the library.\n", bookID);
    }
}

void returnBook() {
    int bookID, i, found = 0;
    printf("Enter the book ID to return: ");
    scanf("%d", &bookID);

    for (i = 0; i < numBooks; i++) {
        if (library[i].bookID == bookID) {
            found = 1;
            if (library[i].isIssued) {
                library[i].isIssued = 0;
                printf("Book returned successfully.\n");
            } else {
                printf("Book was not issued.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found in the library.\n", bookID);
    }
}

void displayBooks() {
    if (numBooks == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("Displaying all available books:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Book ID: %d\n", library[i].bookID);
        printf("Status: %s\n", library[i].isIssued ? "Issued" : "Available");
        printf("------------------------\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Library Management System Menu ---\n");
        printf("1. Add a new book\n");
        printf("2. Remove a book\n");
        printf("3. Issue a book\n");
        printf("4. Return a book\n");
        printf("5. Display all available books\n");
        printf("6. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                removeBook();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                displayBooks();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}
