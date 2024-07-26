#include <stdio.h>

int main() {
    int height, width;

    //prompt for height
    printf("Enter the height of the grill, number between 2 and 12");
    scanf("%d", &height);

    //check if input is in range
    if(height < 2 || height > 12){
        printf("invalid height, please enter a number between 2 and 12");
        return 1; //exit with error

    }

    //prompt for width

    printf("Enter width of grill, number between 2 and 30");
    scanf("%d", &width);

    //check if input in range for width
    if(width < 2 || width > 30){
        printf("invalid width, please enter a number between 2 and 30");
        return 1; // exit with error
    }

    //draw top grill
    printf("+");
    for (int i = 0; i < width - 2; i++) {
        printf("-");
    }
    printf("+\n");


    //draw mid section

    for (int i = 0; i < height - 2; i++) {
        printf("|");
        for (int j = 0; j < width - 2; j++) {
            printf("-");
        }
        printf("|\n");
    }

    //draw bottom grill

    printf("+");
    for (int i = 0; i < width - 2; i++) {
        printf("-");
    }
    printf("+\n");
    
    return 0;
}