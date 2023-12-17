#include <stdio.h>
#include <conio.h>

int josephus(int n, int k) {
    if (n == 1)
        return 1;
    else
        return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main() {
    clrscr();

    int n = 7; // Number of people
    int k = 3; // Count for elimination

    int survivor = josephus(n, k);

    printf("The survivor in Josephus problem is Person %d.\n", survivor);

    getch();
    return 0;
}
