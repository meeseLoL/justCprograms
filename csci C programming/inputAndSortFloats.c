#include <stdio.h>


//functions
void getPrices(float *first, float *second, float *third);
void swap(float *a, float *b);


int main() {
    float price1, price2, price3;

    //call getPrices

    getPrices(&price1, &price2, &price3);

    //print ordered

    printf("The prices are: %.2f %.2f %.2f\n", price1, price2, price3);

    return 0;
}

void getPrices(float *first, float *second, float *third) {
    //prompt user and read prices

    printf("Enter price 1: ");
    scanf("%f", first);
    printf("Enter price 2: ");
    scanf("%f", second);
    printf("Enter price 3: ");
    scanf("%f", third);


    //order using swap
    if (*first > *second) {
        swap(first, second);
    }

    if (*first > *third) {
        swap(first, third);
    }

    if(*second > *third) {
        swap(second, third);
    }
}

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}