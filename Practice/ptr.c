#include <stdio.h>

int findMax(int *num1, int *num2) {
    return (*num1 > *num2) ? *num1 : *num2;
}

int main() {
    int num1, num2;
    
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);
    
    int max = findMax(&num1, &num2);
    
    printf("The maximum of %d and %d is: %d\n", num1, num2, max);
    
    return 0;
}
