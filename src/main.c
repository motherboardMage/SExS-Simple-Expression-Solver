#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stack.h"
#include "../include/infix.h"
#include "../include/globals.h"

// Displays the main menu and handles user choices
int mainMenu();

// Reset stacks to be empty and the pointers to their default values
void resetStacks()
{
    for (int i = 0; i < MAX_LEN; ++i) numStack[i] = -1.0;
    memset(symStack, 0, MAX_LEN * sizeof(int));
    topNum = -1;
    topSym = -1;
}

// Clears any leftover characters from the input buffer
void clearNewline()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    // Allocate both stacks to MAX_LEN for safety and simplicity
    numStack = (double*)calloc(MAX_LEN, sizeof(double));
    symStack = (int*)calloc(MAX_LEN, sizeof(int));

    // Initialize stacks with default values
    for (int i = 0; i < MAX_LEN; ++i) numStack[i] = -1.0;
    memset(symStack, 0, MAX_LEN * sizeof(int));
    
    // Main program loop: repeatedly show menu and process user input
    while(1)
    {
        if(mainMenu() == -1)
        {
            printf("-------------------------------\n"
                   "Error! Couldn't solve equation!\n"
                   "-------------------------------\n");
        }
    }
    // Not reached, but good practice to free memory
    free(numStack);
    free(symStack);
    return 0;
}

// Handles user interaction for menu options
int mainMenu()
{
    int choice;
    printf("Hello! What would you like to do?\n"
           "1. Solve expresison\n"
           "2. Exit the program\n"
           "-> ");
    scanf("%d", &choice);
    clearNewline();

    switch (choice)
    {
    case 1:
        if(!solveInfix())
            return -1;
        break;
    case 2:
        printf("Bye!\n");
        free(numStack);
        free(symStack);
        exit(EXIT_SUCCESS);
    default:
        printf("Feature not built yet or incorrect choice\n");
        return -1;
    }
    resetStacks();
    return 0;
}