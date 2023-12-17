#include <stdio.h>

struct Employee {
    char name[50];
    int empId;
    float basicSalary;
    float allowances;
    float totalSalary;
};

int main() {
    struct Employee employees[5];
    
    printf("Enter details for 5 employees:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Employee ID: ");
        scanf("%d", &employees[i].empId);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basicSalary);
        printf("Allowances: ");
        scanf("%f", &employees[i].allowances);
        
        employees[i].totalSalary = employees[i].basicSalary + employees[i].allowances;
    }
    
    printf("\nEmployee Salary Details:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Employee ID: %d\n", employees[i].empId);
        printf("Total Salary: %.2f\n", employees[i].totalSalary);
    }
    
    return 0;
}
