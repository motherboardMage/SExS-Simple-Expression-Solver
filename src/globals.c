#include <stdlib.h>
#include "../include/stack.h"
#include "../include/infix.h"

// Global stack pointers and indices
double *numStack = NULL; // Number stack (doubles)
int *symStack = NULL;    // Symbol stack (stores ASCII values of operators)
int topNum = -1;         // Top index for number stack
int topSym = -1;         // Top index for symbol stack