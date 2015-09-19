/*
°Ñ¦Ò:http://acm.nudt.edu.cn/~twcourse/MoneyChangingProblem.html
*/
#include<stdio.h>
#define N 7490

int main()
{
	int type[5] = { 1, 5, 10, 25, 50 };
	int methods[N] = { 1 };
	int i, j;

	for (i = 0; i < 5; i++)
		for (j = type[i]; j < N; j++)
			methods[j] += methods[j - type[i]];//DP
		
	int n;
	while (scanf("%d",&n) !=EOF)
		printf("%d\n", methods[n]);

	return 0;
}

