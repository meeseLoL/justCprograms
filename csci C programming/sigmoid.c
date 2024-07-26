#include <stdio.h>
#include <math.h>

int main() {
    printf("x       Sigmoid(x)\n"); //table head

    //create and print table
    for (float x = -5.0; x <= 5.0; x += 1.0) {
        //sigmoid calculation
        float result = 1.0 / (1.0 + exp(-x));
        printf("%.3f   %.3f\n", x, result);
    }
    
    return 0;
}