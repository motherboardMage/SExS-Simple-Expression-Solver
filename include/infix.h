#ifndef INFIX_H
#define INFIX_H

int isNum(char ch);
int precedence(char sym);
double calculate();
char isOperand(char ch);
extern int solveInfix();

#endif