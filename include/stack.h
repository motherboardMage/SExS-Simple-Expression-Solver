#ifndef STACK_H
#define STACK_H

// Stack globals and function declarations
extern double *numStack; // Number stack (doubles)
extern int *symStack;    // Symbol stack (ASCII values)
extern int topNum;
extern int topSym;

void push(double data, char type); // Push to stack
double pop(char type);             // Pop from stack
int isEmpty(char type);            // Check if stack is empty
int isFull(char type);             // Check if stack is full

#endif