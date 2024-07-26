#include <stdio.h>

int main() {
    int amount;

    //get dollar amount from user

    do {
        printf("Enter dollar amount: ");
        scanf("%d", &amount);

        if (amount < 0) {
            printf("Please enter a positive amount.\n");
        }
    } while (amount < 0);

    //calculate min number of bills

    int count = 0;
    int denominations[] = {100, 20, 10, 5, 1};

    for (int i = 0; i < 5; i++) {
        count += amount / denominations[i];
        amount %= denominations[i];
    }

    //dispaly result
    printf("You get %d bill%s back.\n", count, (count ==1) ? "" : "");

    return 0;

}