#include <stdio.h>



//function for collatz sequence
void collatzSequence(int n, int sequence[], int size) {
    sequence[0] = n;
    for (int i = 1; i < size; i++) {
        if (n % 2 == 0)
            n /= 2;
        else 
            n = 3 * n + 1;
        sequence[i] = n;
    }
}

int main() {
    //declare integer array with elements 0-39 size 40

    int array[40];

    //0-9 with 0-9
    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    //fill 10-19 110, 120 etc...

    for (int i = 10; i < 20; i++) {
        array[i] = i * 10;
    }

    //20-25 with 4, 8, 15, 16, 23, 42
    int values[] = {4, 8, 15, 16, 23, 42};
    for (int i = 0; i < 6; i++) {
        array[i + 20] = values[i];
    }

    //fill elements 26-39 with first 14 of collatz starting with seven using function

    int collatz[14];
    collatzSequence(7, collatz, 14);
    for (int i = 0; i < 14; i++) {
        array[i + 26] = collatz[i];
    }

    //print elements of array
    for (int i = 0; i < 40; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;

}