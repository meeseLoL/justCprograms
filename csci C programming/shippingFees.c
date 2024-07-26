#include <stdio.h>
#include <string.h>



double weightOfLetter(char letter) //calc weight for each letter
{
    if (letter >= 'a' && letter <= 'z')
    {
        return (letter - 'a' + 1) * 0.1;
    } else if (letter >= 'A' && letter <= 'Z')
    {
        return (letter - 'A' + 27) * 0.1; //A starts from 2.7kg
    }

    return 0.0; //if invaldid
}


int main() 
{
    char container[101]; //max 100 plus null terminator
    int containerCount = 0;
    double totalShippingFee = 0.0;
    const double ratePerKg = 2.75;

    printf("enter container contents, press '.' to finish:\n ");
    while(1)
    {
        printf("Container: "); //prompt for input
        scanf("%100s", container); //read input
        if (strcmp(container, ".") == 0)
        {
            break; //exit loop if input .
        }

        int len = strlen(container);
        double weight1 = 0.0, weight2 = 0.0;
        for (int i = 0; i < len / 2; i++)
        {
            weight1 += weightOfLetter(container[i]);
        }
        for (int i = len / 2; i < len; i++)
        {
            weight2 += weightOfLetter(container[i]);
        }

        double maxWeight = weight1 > weight2 ? weight1 : weight2;
        double shippingFee = maxWeight * ratePerKg;
        totalShippingFee += shippingFee;
        containerCount++;

        //debugging uncomment next line

        //printf("Container: %s, Shipping Fee: $%.2f\n", container, shippingFee)
    }
    printf("%d containers, total shipping fee $%.2f\n", containerCount, totalShippingFee);
    return 0;

    }




