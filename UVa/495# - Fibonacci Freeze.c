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
			for (i = 199; i >= 0; i--)//�q�̫�}�l ���e�ˬd��Ĥ@�Ӥ���0���Ʀr
				if (Fib[n][i])break;

			printf("%d", Fib[n][i--]);//�L�X�Ĥ@��

			for (; i >= 0; i--)
				printf("%08d", Fib[n][i]);//�n��0�H�K�ʤ֦��
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
		Fib[i][j] += Fib[i - 1][j] + Fib[i - 2][j];//�ۤv(���L�i��)�A�[�W�e2�ӼƦr
		if (Fib[i][j] >= 100000000)//���i��
		{
			Fib[i][j] -= 100000000;
			Fib[i][j + 1]++;
		}
		}
}