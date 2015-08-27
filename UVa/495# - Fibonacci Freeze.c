#include<stdio.h>

int Fib[5001][200] = { 0 };
void fib(int Fib[][200]);

int main(){

	int i, n;


	fib(Fib);

	while (scanf("%d", &n) != EOF)
	{
		printf("The Fibonacci number for %d is ", n);

		if (!n)printf("0");

		else {
			for (i = 199; i >= 0; i--)//眖程秨﹍ ┕玡浪琩材ぃ0计
				if (Fib[n][i])break;

			printf("%d", Fib[n][i--]);//材

			for (; i >= 0; i--)
				printf("%08d", Fib[n][i]);//璶干0ぶ计
		}
		printf("\n");
	}

	return 0;
}

void fib(int Fib[][200]){

	Fib[0][0] = 0;
	Fib[1][0] = 1;
	Fib[2][0] = 1;

	int i, j;

	for (i = 3; i <= 5000; i++)
		for (j = 0; j < 199; j++)
		{
		Fib[i][j] += Fib[i - 1][j] + Fib[i - 2][j];//(Τ礚秈)玡2计
		if (Fib[i][j] >= 100000000)//货秈
		{
			Fib[i][j] -= 100000000;
			Fib[i][j + 1]++;
		}
		}
}