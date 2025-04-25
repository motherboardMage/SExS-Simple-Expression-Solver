#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"
#include "../include/globals.h"

int isEmpty(char type)
{
    switch (type)
    {
    case 'N':
        return topNum == -1;
    case 'S':
        return topSym == -1;
    default:
        printf("Error! Invalid type\n");
        return 1;
    }
}

int isFull(char type)
{
    switch (type)
    {
    case 'N':
        return topNum == ((4 * MAX_LEN) / 5) - 1;
    case 'S':
        return topSym == ((MAX_LEN / 5) - 1);
    default:
        printf("Error! Incorrect type\n");
        return -1;
    }
}

void push(double data, char type)
{
    switch (type)
    {
    case 'N':
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
    case 'S':
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
    case 'N':
        val = numStack[topNum];
        numStack[topNum] = -1.0;
        topNum--;
        return val;
    case 'S':
        val = symStack[topSym];
        symStack[topSym] = 0;
        topSym--;
        return val;
    default:
        printf("Error! Invalid token type!\n");
        return -1.0;
    }
}