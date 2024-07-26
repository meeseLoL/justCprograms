#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"

//source file name to read plaintext from
//the destination file name to write hashes to
//if user does not supply file names error message and exit with status code 1
//each line in source file is read in, hashed, and the hash written to destination file
//each input line should have its newline, if presesnt, trimmed off before hashing..

int main(int argc, char* argv[]) 
{
    printf("Enter name of file to display (Test File 1.txt or Test File 2.txt)");
    char filename[50];
    fgets(filename, sizeof(filename), stdin); //fgets instead of scanf

    //remove newline character at end of file name if present
    size_t len = strlen(filename);
    if (filename[len - 1] == '\n')
    {
        filename[len - 1] = '\0';
    }

    //open file for reading
    FILE *in = fopen(filename, "r");
    if (in == NULL)
    {
        perror("Error opening file");
        return 1; //error if file can not open
    }

    //determine file for writing
    char writeFile[100];
    snprintf(writeFile, sizeof(writeFile), "Hashed %s", filename); //prepend hashed to source filename snprintf is used to create name of writeFile prepending "Hashed"

    //open writefile
    FILE *out = fopen(writeFile, "w");
    if (out == NULL)
    {
        perror("error opening writeFile");
        fclose(in); //close source file before exit
        return 1;
    }

    //store content of file display as string on line
    char myString[100];
    
    //read and print every line of file
    while (fgets(myString, sizeof(myString), in) != NULL)
    {
        //remove newline if character pressent
        len = strlen(myString);
        if (myString[len - 1] == '\n') myString[len - 1] = '\0';

        //hash line
        char *hash = md5(myString, strlen(myString)); //md5 hash of the line "myString" 

        //print hash and original line of text
        fprintf(out, "%s\n", hash); //write hash to writeFile

        free(hash); //free memory used by hash
    }

    //close file
    fclose(in);

    return 0;

}