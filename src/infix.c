#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../include/stack.h"
#include "../include/infix.h"
#include "../include/globals.h"

// Returns the precedence index of an operator in symArr, or -1 if not found
int precedence(char op) {
    switch(op) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 1;
        default: return -1;
    }
}

// Returns 1 if ch is a digit, 0 otherwise
int isNum(char ch)
{
    return (ch >= '0' && ch <= '9');
}

// Returns 1 if the operator is right-associative (currently only '^')
int isRightAssociative(char op) {
    return op == '^';
}

// Pops two numbers and one operator, performs the operation, and pushes the result
int calculate()
{
    double a, b, res;
    b = pop('N');
    a = pop('N');
    // symStack[topSym] holds the ASCII value of the operator
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
    pop('S'); // Remove the operator after calculation
    push(res, 'N');
    return 0;
}

// Parses and evaluates an infix expression from user input
int solveInfix()
{
    int num = 0, chp;
    char *exp = (char*)calloc(MAX_LEN, sizeof(char));
    printf("Enter the expression: \n");
    fgets(exp, MAX_LEN, stdin);

    // Remove trailing newline from input expression, if present
    size_t len = strlen(exp);
    if (len > 0 && exp[len - 1] == '\n') exp[len - 1] = '\0';

    char *ch = exp;

    while(*ch != '\0' && *ch != '\n')
    {
        if(isNum(*ch))
        {
            num = 0;
            // Parse multi-digit integer
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
            // Fix: For correct precedence, pop while (tsp <= chp) or (tsp == chp and not right-associative)
            while (!isEmpty('S')) {
                int topOp = symStack[topSym];
                int tsp = precedence(topOp);
                // Pop while stack top has higher or equal precedence (for left-associative)
                // For right-associative, only pop if stack top has higher precedence
                if ((tsp <= chp && !isRightAssociative((char)topOp)) ||
                    (tsp < chp && isRightAssociative((char)topOp))) {
                    if (calculate() == -1) {
                        free(exp);
                        return -1;
                    }
                } else {
                    break;
                }
            }
            // Push operator as its ASCII value
            push((double)(*ch), 'S');
            ch++;
        }
    }
    // Process any remaining operators
    while(!isEmpty('S'))
    {
        if(calculate() == -1)
        {
            free(exp);
            return -1;
        }
    }
    printf("%s = %.10g\n\n", exp, numStack[0]);
    free(exp);
    return 1;
}