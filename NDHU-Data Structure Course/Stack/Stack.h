#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAXSIZE 100

typedef struct{
	int key;
	int value;
}element_t;

typedef struct{
	int top;
	int size;
	element_t container[MAXSIZE];
}stack_t;

void create(stack_t *, int);
bool isFull(stack_t *);
bool isEmpty(stack_t *);
void push(stack_t *, element_t *);
element_t *pop(stack_t *);
element_t *popall(stack_t *);

#endif

