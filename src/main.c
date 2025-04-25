#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stack.h"
#include "../include/infix.h"
#include "../include/globals.h"

int mainMenu();

void clearNewline()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    int symStackSize = MAX_LEN / 5;
    int numStackSize = MAX_LEN - symStackSize;

    // Allocate memory to the arrays
    numStack = (double*)calloc(numStackSize, sizeof(double));
    symStack = (int*)calloc(symStackSize, sizeof(int));

    // Fill the arrays with "empty element identifiers"
    for (int i = 0; i < numStackSize; ++i) numStack[i] = -1.0;
    memset(symStack, 0, symStackSize * sizeof(int));
    
    while(1)
    {
        if(mainMenu() == -1)
        {
            printf("-------------------------------\n"
                   "Error! Couldn't solve equation!\n"
                   "-------------------------------\n");
        }
    }
    // Not reached, but good practice
    free(numStack);
    free(symStack);
    return 0;
}

int mainMenu()
{
    int choice;
    printf("Hello! What would you like to do?\n"
           "1. Solve infix\n"
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
    return 0;
}