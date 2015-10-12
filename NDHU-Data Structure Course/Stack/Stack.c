#include"Stack.h"
#include<stdlib.h>
#include<stdio.h>

void create(stack_t *sPtr, int size)
{
	sPtr->size = size;
	sPtr->top = -1;//empty

}
bool isFull(stack_t *sPtr)
{
	return sPtr->top == sPtr->size - 1 ? true : false; 
}
bool isEmpty(stack_t * sPtr)
{
	return sPtr->top == -1 ? true : false;
}
void push(stack_t * sPtr, element_t * element)
{
	if (isFull(sPtr))
	{
		printf("Stack is full.\n");
		return;
	}
	else
	{

		sPtr->top++; 
		sPtr->container[sPtr->top] = *element;
	}

}
element_t *pop(stack_t * sPtr)
{


	if (isEmpty(sPtr))
	{
		printf("Stack is empty.\n");
		return NULL;
	}
	else
	{
		element_t *temp = calloc(1, sizeof(element_t));
		*temp = sPtr->container[sPtr->top];
		sPtr->top--;

		return temp;
	}


}
element_t *popall(stack_t * sPtr)
{


	if (isEmpty(sPtr))
	{
		printf("Stack is empty.\n");
		return NULL;
	}
	else
	{
		element_t *ele = malloc(sizeof(element_t)*sPtr->top);
		element_t *temp;
		int count = 0;

		while (!isEmpty(sPtr))
		{	
			temp = pop(sPtr);
			(ele + count)->key = temp->key;
			count++;
		}
		return ele;
	}



}

