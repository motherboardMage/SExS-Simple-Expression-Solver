#ifndef STACK_H
#define STACK_H

typedef struct {
    float data;
    struct stackNode *prev;
}stackNode;

stackNode *topNode;

void push(int data);
int pop();
int top();
int isEmpty();

#endif STACK_H