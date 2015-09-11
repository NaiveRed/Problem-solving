#include<stdio.h>

int f91(int num);
int main(){

	int num;

	while (scanf("%d", &num) != EOF&&num)
		printf("f91(%d) = %d\n", num, f91(num));

	return 0;
}
int f91(int num)
{
	return num > 100 ? num - 10 : f91(f91(num + 11));
}