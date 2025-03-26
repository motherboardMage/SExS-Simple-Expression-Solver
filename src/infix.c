#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"
#include "../include/infix.h"

int main()
{
    topNode = NULL;
    
    char *eqn = (char*)calloc(100, sizeof(char));
    printf("Enter equation: ");
    scanf("%s", eqn);

    char orig[] = eqn;
    calculateInfix(eqn);
}