#include <stdio.h>
#include <conio.h>

#define MAX_PATIENTS 10

int front = -1, rear = -1;
int patientQueue[MAX_PATIENTS];

void enqueue(int patient) {
    if (rear == MAX_PATIENTS - 1) {
        printf("Clinic is full. Patient %d needs to wait.\n", patient);
        return;
    } else {
        if (front == -1)
            front = 0;
        rear++;
        patientQueue[rear] = patient;
        printf("Patient %d has entered the clinic.\n", patient);
    }
}

void dequeue() {
    if (front == -1) {
        printf("No patients in the clinic.\n");
        return;
    } else {
        int patient = patientQueue[front];
        printf("Doctor attending to Patient %d.\n", patient);

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}

void displayPatientQueue() {
    if (front == -1) {
        printf("No patients in the clinic.\n");
        return;
    } else {
        printf("Patients in the clinic: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", patientQueue[i]);
        printf("\n");
    }
}

int main() {
    clrscr();

    enqueue(101);
    enqueue(102);
    enqueue(103);

    displayPatientQueue();

    dequeue();

    displayPatientQueue();

    getch();
    return 0;
}
