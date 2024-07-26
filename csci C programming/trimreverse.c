#include <stdio.h>
#include <string.h>



// Max string length
#define STR_MAX 100

// Function prototypes here:

int stringLength(const char *str);
void trim(char *str);
void reverse(char *str);



// Main function
int main()
{
    char input[STR_MAX];
	
    // Loop until we break out
    while (1)
    {
        printf("Enter a string: ");
        fgets(input, STR_MAX, stdin);      // Finish this call to fgets
        if (input[0] == '.')                      // Break out of loop when first char is '.'
	{
            break;
        }
		
        // Trim the newline
        trim(input);

        // Print the trimmed string
        printf("After trim: %s\n", input);
		
        // Reverse the string
        reverse(input);
		
        // Print the reversed string
        printf("Reversed: %s\n", input);
    }

    return 0;
}

//implement stringLength

int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}


//implement trim
void trim(char *str) {
    int length = stringLength(str);
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

//Implementation of reverse
void reverse(char *str)
{
    int length = stringLength(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}