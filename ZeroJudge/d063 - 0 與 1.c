#include<stdio.h>

int main()
{
	putchar(1 ^ (getchar() - '0') + '0');
	return 0;
}