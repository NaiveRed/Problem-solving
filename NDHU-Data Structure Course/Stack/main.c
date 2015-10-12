#include <stdio.h>
#include"Stack.h"
#include<stdlib.h>
#define SIZE 10

int main()
{

	stack_t *sPtr;
	sPtr = calloc(1, sizeof(stack_t));

	create(sPtr, SIZE);

	printf("請輸入選項(-1結束)：\n(1)push值至堆疊\n(2)pop頂端值\n(3)pop all\n");

	element_t *e = malloc(sizeof(element_t));
	element_t *ele = NULL;

	int command, temp, i = 0, j;

	while (scanf("%d", &command) && command != -1)
	{

		switch (command)
		{
		case 1:
			scanf("%d", &temp);
			e->key = temp;
			push(sPtr, e);
			i++;
			break;
		case 2:
			if (e = pop(sPtr))
			{
				printf("%d\n", e->key);
				i--;
			}
			else e = malloc(sizeof(element_t));
			break;
		case 3:
			ele = popall(sPtr);
			for (j = 0; j < i; j++)//把所有pop的值輸出出來
				printf("%d\n", (ele + j)->key);
			i = 0;
		}
	}

	
	free(sPtr);
	free(e);
	free(ele);

	system("pause");
	return 0;
}

