#include<stdio.h>

/*
  -  0
 | | 1 2
  -  3
 | | 4 5
  -  6
 */

const int LCD[10][7] = {
{ 1, 1, 1, 0, 1, 1, 1 },
{ 0, 0, 1, 0, 0, 1, 0 },
{ 1, 0, 1, 1, 1, 0, 1 },
{ 1, 0, 1, 1, 0, 1, 1 },
{ 0, 1, 1, 1, 0, 1, 0 },
{ 1, 1, 0, 1, 0, 1, 1 },
{ 1, 1, 0, 1, 1, 1, 1 },
{ 1, 0, 1, 0, 0, 1, 0 },
{ 1, 1, 1, 1, 1, 1, 1 },
{ 1, 1, 1, 1, 0, 1, 1 }
};

void dash(int size, int num, int lcd);
void ver(int size, int num, int lcd1, int lcd2);
int main(){

	int size;
	char num[10];
	
	while (scanf("%d %s", &size, num) && size != 0)
	{
		int i;
		
		for (i = 0; num[i]; i++)
		{
			if (i)
				putchar(' ');
			dash(size, num[i] - '0', 0);
		}

		puts("");
		int j;
		
		for (j = 0; j < size; j++)
		{
			for (i = 0; num[i]; i++)
			{
				if (i)
					putchar(' ');
				ver(size, num[i] - '0', 1, 2);
			}
			puts("");
		}
		
		for (i = 0; num[i]; i++)
		{
			if (i)
				putchar(' ');
			dash(size, num[i] - '0', 3);
		}
		
		puts("");
		
		for (j = 0; j < size; j++)
		{
			for (i = 0; num[i]; i++)
			{
				if (i)
					putchar(' ');
				ver(size, num[i] - '0', 4, 5);
			}
			puts("");
		}
		
		for (i = 0; num[i]; i++)
		{
			if (i)
				putchar(' ');
			dash(size, num[i] - '0', 6);
		}
		
		printf("\n\n");

	}

	return 0;
}
void dash(int size,int num,int lcd){
	
	int i;

	putchar(' ');

	if (LCD[num][lcd])
		for (i = 0; i < size;i++)
			putchar('-');
	else 	
		for (i = 0; i < size; i++)
		putchar(' ');

	putchar(' ');
		
	}
void ver(int size, int num, int lcd1, int lcd2){

	int i;
	
	if (LCD[num][lcd1])
		putchar('|');
	else putchar(' ');
	
	for (i = 0;i<size;i++)
		putchar(' ');

	if (LCD[num][lcd2])
		putchar('|');
	else putchar(' ');
}

