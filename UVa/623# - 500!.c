#include<stdio.h>
#define N 1001
#define M 3000

int factorial[N][M] = {0};

void Factorial();
int main(){

	Factorial();
	
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d!\n", n);
		int i;
		for (i = M - 1; !factorial[n][i]; i--);
		for (; i >= 0; i--)
			printf("%d", factorial[n][i]);
		puts("");
	}

	return 0;
}

void Factorial()
{
	factorial[0][0] = 1;
	factorial[1][0] = 1;
	int i, j;
	for (i = 2; i <N ; i++)
		for (j = 0; j < M-1; j++)
		{
		factorial[i][j] += factorial[i - 1][j] * i;
		if (factorial[i][j] >= 10)
		{
			factorial[i][j + 1]+=factorial[i][j]/10;
			factorial[i][j] %= 10;
		}
		}
}