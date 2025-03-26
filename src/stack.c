#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

void push(int data)
{
    stackNode *newNode = (stackNode*)calloc(1, sizeof(stackNode));
    newNode->data = data;

    if(topNode == NULL)
    {
        topNode = newNode;
        newNode->prev = NULL;
    }

    newNode->prev = topNode;
    topNode = newNode;
}

int pop()
{
    // Add empty stack safety where it will be called
    int ret = topNode->data;
    stackNode *temp = (stackNode*)malloc(sizeof(stackNode));
    temp = topNode;
    
    topNode = topNode->prev;
    free(temp);
    temp = NULL;

    return ret;
}