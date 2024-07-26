#include <stdio.h>

//functions

void fill_0_9(int *array);
void fill_10_19(int *array);
void fill_20_25(int *array);
void fill_26_39(int *array);
int nextCollatz(int n);
void printArray(int *array, int size);


//fills 0-9 with for loop
void fill_0_9(int *array) {
    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }
}

//fills 10-19 with 100 110 120 etc
void fill_10_19(int *array) {
    for (int i = 10; i < 20; i++) {
        *(array + i) = 100 + (i - 10) * 10;
    }
}

//fill 20-25 4, 8, 15, 16, 23, 42
void fill_20_25(int *array) {
    int values[] = {4, 8, 15, 16, 23, 42};
    for (int i = 0; i < 6; i++) {
        *(array + 20 + i) = values[i];
    }
}

//first 14 of collatz start 7
void fill_26_39(int *array) {
    int n = 7;
    for (int i = 26; i < 40; i++) {
        array[i] = n;
        n = nextCollatz(n);
    }
}

//collatz
int nextCollatz(int n) {
    if (n % 2 == 0)
            n /= 2;
        else 
            n = 3 * n + 1;
        return n; 
}

//print
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

//main
int main() {
    int array[40];
    fill_0_9(array);
    fill_10_19(array);
    fill_20_25(array);
    fill_26_39(array);
    printArray(array, 40);
    return 0;
}