#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void display(Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

void addPolynomials(Node* poly1, Node* poly2, Node** result) {
    while (poly1 != NULL || poly2 != NULL) {
        int coeff1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : 0;
        int coeff2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 0;

        int sum_coeff = coeff1 + coeff2;
        int sum_exp = (exp1 > exp2) ? exp1 : exp2;

        Node* term = createNode(sum_coeff, sum_exp);
        term->next = *result;
        *result = term;

        if (poly1 != NULL) poly1 = poly1->next;
        if (poly2 != NULL) poly2 = poly2->next;
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;

    poly1 = createNode(3, 2);
    poly1->next = createNode(4, 1);
    poly1->next->next = createNode(5, 0);

    poly2 = createNode(1, 3);
    poly2->next = createNode(2, 2);
    poly2->next->next = createNode(3, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    addPolynomials(poly1, poly2, &result);

    printf("Sum of Polynomials: ");
    display(result);

    return 0;
}
