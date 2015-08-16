#include<cstdio>
#define N 101
#define NEWLINE {putchar('\n');putchar(' '); putchar(' ');putchar(' ');putchar(' ');putchar(' ');putchar(' ');}

int prime[30];

inline int getPrime();
inline int input();
int main()
{

	int total(getPrime());

	int num;

	while (num = input())
	{
		printf("%3d! =", num);

		for (int i = 1; i <= total&&prime[i]<=num; i++)
		{
			int temp(num), count(0);

			while (temp >= prime[i])
			{
				temp /= prime[i];
				count += temp;
			}

			if (!(i % 16) && i >= 16)//剛好15時不要多新的一行
			{
				NEWLINE
			}

			printf("%3d", count);

			
		}

		putchar('\n');
	}

	return 0;
}
int getPrime()
{
	int notPrime[N]{true, true};
	int count(1);
	for (int i = 2; i < N; i++)
	{
		if (!notPrime[i])
		{
			for (int j = i << 1; j < N; j += i)
				notPrime[j] = true;

			prime[count++] = i;
		}

	}
	return count - 1;
}
int input()
{
	char c;
	int num(0);
	while ((c = getchar()) != '\n')
	{
		num = num * 10 + c - '0';
	}

	return num;

}