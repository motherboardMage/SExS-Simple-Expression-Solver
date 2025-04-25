#ifndef STACK_H
#define STACK_H

extern double *numStack;
extern int *symStack;
extern int topNum;
extern int topSym;

void push(double data, char type);
double pop(char type);
int isEmpty(char type);
int isFull(char type);

#endif