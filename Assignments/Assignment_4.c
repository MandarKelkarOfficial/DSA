#include <stdio.h>
#include <stdlib.h>

// Entity types
enum EntityType {
    STUDENT,
    STAFF,
    HOD_DEAN_DIRECTOR
};

// Structure to represent an entity
struct Entity {
    enum EntityType type;
    int priority;
};

// Function to swap two entities
void swap(struct Entity* a, struct Entity* b) {
    struct Entity temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort entities based on priority
void selectionSort(struct Entity entities[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (entities[j].priority > entities[maxIndex].priority) {
                maxIndex = j;
            }
        }
        swap(&entities[i], &entities[maxIndex]);
    }
}

int main() {
    int numEntities;
    printf("Enter the number of entities: ");
    scanf("%d", &numEntities);

    struct Entity entities[numEntities];
    for (int i = 0; i < numEntities; i++) {
        int type;
        printf("Enter entity type (1 for STUDENT, 2 for STAFF, 3 for HOD_DEAN_DIRECTOR): ");
        scanf("%d", &type);

        entities[i].type = (enum EntityType)(type - 1);

        printf("Enter priority (1 for STUDENT, 2 for STAFF, 3 for HOD_DEAN_DIRECTOR): ");
        scanf("%d", &entities[i].priority);
        printf("\n");
    }

    // Sort entities based on priority
    selectionSort(entities, numEntities);

    // Serve entities in sorted order
    printf("Serving entities in the lift:\n");
    for (int i = 0; i < numEntities; i++) {
        printf("Entity type: ");
        switch (entities[i].type) {
            case STUDENT:
                printf("Student");
                break;
            case STAFF:
                printf("Staff");
                break;
            case HOD_DEAN_DIRECTOR:
                printf("HOD/Dean/Director");
                break;
        }
        printf("\n");
    }

    return 0;
}
