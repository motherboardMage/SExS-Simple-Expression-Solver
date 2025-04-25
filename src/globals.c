#include <stdlib.h>
#include "../include/stack.h"
#include "../include/infix.h"

double *numStack = NULL;
int *symStack = NULL;
int topNum = -1;
int topSym = -1;
char symArr[8] = {'(', '{', '[', '^', '*', '/', '+', '-'};