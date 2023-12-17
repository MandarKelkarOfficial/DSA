#include <stdio.h>

int main() {
    int marks[5];
    int sum = 0;
    
    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        sum += marks[i];
    }
    
    float average = (float)sum / 5;
    
    printf("\nSum of subject marks: %d\n", sum);
    printf("Average of subject marks: %.2f\n", average);
    
    return 0;
}
