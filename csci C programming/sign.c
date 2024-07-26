#include <stdio.h>


int main() {

    int height;

    //prompt user to enter height
    printf("Enter height of the sign enter a number bettween 3 and 12: ");
    scanf("%d", &height);

    //check if input is in range
    if (height < 3 || height > 12) {
        printf("Invalid height, please enter a nubmer between 3 and 12");
        return 1; //exit with error code
    }

    // draw flag
    printf("|--------+\n");
    printf("|Justin Ballard|\n");
    printf("|--------+\n");

    int i;

    //draw | based on user input
    for (i = 0; i < height -3; i++) {
        printf("|\n");
    }

}