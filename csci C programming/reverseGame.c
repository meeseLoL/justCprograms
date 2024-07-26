#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int getInt(char prompt[], int min, int max);
int isSorted(int arr[], int len);
void printBoard(int arr[], int len);
void fillBoard(int arr[], int len);
void shuffleBoard(int arr[], int len);
void reverse(int arr[], int len, int amtToReverse);


void reverse (int arr[], int len, int amtToReverse)
{
    int temp;
    for (int i = 0; i < amtToReverse / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[amtToReverse - i - 1];
        arr[amtToReverse - i - 1] = temp;
    }
}


int main()
{
    // Seed the random number generator
    srandom(time(NULL));
        
    // Ask user for length of game, from 3-20
    int boardLength = getInt("Enter size of board: ", 3, 20);
    
    // Create board.
    int board[boardLength];
    
    // Fill board in order with numbers 1..boardLength.
    fillBoard(board, boardLength);
    
    // Shuffle board.
    // I recommend initially only uncommenting the shuffleBoard line
    // so it doesn't get stuck in an infinite loop. Once shuffleBoard
    // is working, uncomment the rest of the loop.
    do
    {
        shuffleBoard(board, boardLength);
    }
    while (isSorted(board, boardLength));
    
    // Print board
    printBoard(board, boardLength);
    
    int gameOver = 0;
    int moves = 0;
    while (!gameOver)
    {
        // Ask user for amount to reverse
        int amt = getInt("How many to reverse? ", 2, boardLength);
        
        // Reverse the first (amt) numbers.
        reverse(board, boardLength, amt);
        
        // Print the board
        printBoard(board, boardLength);
        
        // Check to see if the game is over
        gameOver = isSorted(board, boardLength);
        
        moves++;
    }
    printf("You won in %d moves!\n", moves);
}

// Get an integer from the user.
//   Display the prompt.
//   Get input from user.
//   Check that the input is between the min and max, inclusive.
//   If not, display error message that includes the min and max,
//     then loop back to get input again.
int getInt(char prompt[], int min, int max)
{
    int input;
    while (1) 
    {
        printf("%s", prompt);
        scanf("%d", &input);
        if (input >= min && input <= max)
        {
            return input;
        }
        printf("Value must be in range %d-%d", min, max);
    }
    
}

// Determine if the array is sorted (in order).
// Loop through the array, looking at adjacent
// elements. If any pair is out of order, return 0 (false).
int isSorted(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        // If this element and the next one are out of order,
        // the array is not sorted. Return 0 (false) immediately.
        if (arr[i] > arr[i+1])
            return 0;
    }

    // If we got all the way through the loop,
    // the array must be sorted.
    return 1;
}

// Display the board
void printBoard(int arr[], int len)
{
    printf("Board:");
    for (int i = 0; i < len; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

// Fill board with the numbers 1..len
void fillBoard(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        arr[i] = i + 1;
    }
}

// Shuffle the board
void shuffleBoard(int arr[], int len)
{
    for (int i = len - 1; i > 0; i--)
    {
        int j = rand() % (i +1); //random index from 0-i
        //swap arr[i] with element at the random index
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}