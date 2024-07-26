#include <stdio.h>

int main() {
    //declare vars for input and output fractions
    int num1, den1, num2, den2, sum_num, sum_den;

    //prompt user to enter first fraction
    printf("this program will sum 2 fractions.\n");
    printf("Input first fraction: ");
    scanf("%d/%d", &num1, &den1);

    //prompt for second fraction
    printf("Input the second fraction: ");
    scanf("%d/%d", &num2, &den2);

    //calculate the sum of fractions

    sum_num = (num1 * den2) + (num2 * den1);
    sum_den = den1 * den2;

    //result
    printf("The sum is: %d/%d\n", sum_num, sum_den);
}