#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"
#include "../include/globals.h"

// Returns 1 if the stack of given type is empty, 0 otherwise
int isEmpty(char type)
{
    switch (type)
    {
    case 'N': // Number stack
        return topNum == -1;
    case 'S': // Symbol stack
        return topSym == -1;
    default:
        printf("Error! Invalid type\n");
        return 1;
    }
}

// Returns 1 if the stack of given type is full, 0 otherwise
int isFull(char type)
{
    switch (type)
    {
    case 'N': // Number stack
        return topNum == MAX_LEN - 1;
    case 'S': // Symbol stack
        return topSym == MAX_LEN - 1;
    default:
        printf("Error! Incorrect type\n");
        return -1;
    }
}

// Pushes a value onto the number or symbol stack depending on type
void push(double data, char type)
{
    switch (type)
    {
    case 'N': // Push to number stack
        if (!isFull('N'))
        {
            topNum++;
            numStack[topNum] = data;
        }
        else
        {
            printf("Error! Number stack full\n");
        }
        break;
    case 'S': // Push to symbol stack (cast double to int for char storage)
        if (!isFull('S'))
        {
            topSym++;
            symStack[topSym] = (int)data;
        }
        else
        {
            printf("Error! Symbol stack full\n");
        }
        break;
    default:
        printf("Error! Invalid token type!\n");
        return;
    }
}

// Pops a value from the number or symbol stack depending on type
// For symbol stack, returns the ASCII value as double
double pop(char type)
{
    if (isEmpty(type))
    {
        printf("Error! Stack is empty!\n");
        return -1.0;
    }
    double val;
    switch (type)
    {
    case 'N': // Pop from number stack
        val = numStack[topNum];
        numStack[topNum] = -1.0; // Optional: reset slot
        topNum--;
        return val;
    case 'S': // Pop from symbol stack (returns ASCII value as double)
        val = symStack[topSym];
        symStack[topSym] = 0; // Optional: reset slot
        topSym--;
        return val;
    default:
        printf("Error! Invalid token type!\n");
        return -1.0;
    }
}