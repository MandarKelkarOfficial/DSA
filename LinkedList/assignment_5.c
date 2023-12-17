#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
    struct Term* prev;
};

typedef struct Term Term;

// Function to create a new term
Term* createTerm(int coeff, int exp) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    newTerm->prev = NULL;
    return newTerm;
}

// Function to insert a term at the end of the polynomial
void insertTerm(Term** poly, int coeff, int exp) {
    Term* newTerm = createTerm(coeff, exp);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
        newTerm->prev = current;
    }
}

// Function to display a polynomial
void displayPolynomial(Term* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    Term* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coefficient + poly2->coefficient;
            if (sumCoeff != 0) {
                insertTerm(&result, sumCoeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add any remaining terms from both polynomials
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;
    Term* result = NULL;

    // Accept the first polynomial
    insertTerm(&poly1, 3, 4);
    insertTerm(&poly1, 2, 2);
    insertTerm(&poly1, 5, 0);

    // Accept the second polynomial
    insertTerm(&poly2, 4, 3);
    insertTerm(&poly2, 1, 2);
    insertTerm(&poly2, 2, 1);

    // Display the first polynomial
    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    // Display the second polynomial
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Add the polynomials
    result = addPolynomials(poly1, poly2);

    // Display the result
    printf("Result: ");
    displayPolynomial(result);

    // Free memory
    free(poly1);
    free(poly2);
    free(result);

    return 0;
}
