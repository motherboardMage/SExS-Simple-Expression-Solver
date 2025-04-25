#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/stack.h"
#include "../include/infix.h"
#include "../include/globals.h"

int precedence(char sym)
{
    for(int i = 0; i < 8; i++)
    {
        if(sym == symArr[i])
            return i;
    }
    return -1;
}

int isNum(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int isRightAssociative(char op) {
    return op == '^';
}

int calculate()
{
    double a, b, res;
    b = pop('N');
    a = pop('N');
    switch ((int)symStack[topSym])
    {
    case '^':
        res = pow(a, b);
        break;
    case '/':
        if (b == 0.0)
            return -1;
        res = a / b;
        break;
    case '*':
        res = a * b;
        break;
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    default:
        printf("--------------------------------------------------\n"
               "Error! Invalid symbol! Please check your equation!\n"
               "--------------------------------------------------\n");
        return -1;
    }
    pop('S'); // Always pop the operator after calculation
    push(res, 'N');
    return 0;
}

int solveInfix()
{
    int num = 0;
    int chp;
    char *exp = (char*)calloc(MAX_LEN, sizeof(char));
    printf("Enter the infix expression: \n");
    fgets(exp, MAX_LEN, stdin);
    char *ch = exp;

    while(*ch != '\0' && *ch != '\n')
    {
        if(isNum(*ch))
        {
            num = 0;
            while(isNum(*ch))
            {
                num = num * 10 + (*ch - '0');
                ch++;
            }
            push((double)num, 'N');
        }
        else if(*ch == ' ')
        {
            ch++;
            continue;
        }
        else
        {
            chp = precedence(*ch);
            if(chp == -1)
            {
                printf("Error! Invalid symbol in expression.\n");
                free(exp);
                return -1;
            }
            while(!isEmpty('S')) {
                int topOp = symStack[topSym];
                int tsp = precedence(topOp);
                if (tsp < chp || (tsp == chp && !isRightAssociative((char)topOp))) {
                    if(calculate() == -1)
                    {
                        free(exp);
                        return -1;
                    }
                } else {
                    break;
                }
            }
            push((double)(*ch), 'S');
            ch++;
        }
    }
    // Process remaining operators
    while(!isEmpty('S'))
    {
        if(calculate() == -1)
        {
            free(exp);
            return -1;
        }
    }
    printf("%s = %lf\n", exp, numStack[0]);
    free(exp);
    return 1;
}