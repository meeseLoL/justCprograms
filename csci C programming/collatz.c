#include <stdio.h>

//function to prompt user and return starting number

int getStart() {
    int num;
    do {
        printf("Enter the starting number: ");
        scanf("%d", &num);
        if (num <= 0)
            printf ("number should be positive integer.");
    } while (num <= 0);
    return num;
}



//function to generate next number in collatz

int nextCollatz(int n) {
    if (n % 2 == 0)
        return n / 2;
    else
        return 3 * n + 1;
}

int main() {
    //call getStart to get starting number

    int start = getStart();
    int length = 0;
    int current = start;

    //print collatz
    printf("Collatz sequence: ");
    while (current != 1) {
        printf("%d, ", current);
        current = nextCollatz(current);
        length++;
    }

    printf("1\n");

    //print length of sequence
    printf("Length: %d\n", length + 1);

    return 0;
}