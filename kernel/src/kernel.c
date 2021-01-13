#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef char* bootID;



char* generateRandomString(size_t length) 
{
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 
    char* randomStringResult = NULL;
    
    if (length) 
    {
        randomStringResult = malloc(sizeof(char) * (length + 1));

        if (randomStringResult) 
        {
            for (int i = 0; i < length; i++)
            {
                srand(time(NULL));
                int key = rand() % (int)(sizeof(charset) - 1);
                printf("%d \n", key);
                char val = charset[key];
                randomStringResult[i] = charset[key];
            }
            randomStringResult[length] = "\0";
        }

    }


    return randomStringResult;
}


bootID generateBootID() 
{
    bootID bootID = generateRandomString(50); // maybe not hardcoded TODO
    // TODO MAybe more code here
    if (bootID == NULL) 
    {
        printf("[KernelError] We were unable to generate your unique Boot ID. Please restart your computer. If this does not resolve the issue, please go to cmty.cletyxo.com and describe your problem to our community. \n");
    // Exit out here :)
    }
    return bootID;
}


int main() 
{
    bootID string = generateBootID();
    printf("ID: %s \n", string);
}


bootID kernelGetBootID() { return }