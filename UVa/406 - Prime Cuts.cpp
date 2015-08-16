#include<cstdio>
#include<cmath>
#define N 1001

int prime[N]{1};
int amountOfPrime[N]{0, 1};

inline int getPrime();
inline int input();
int main()
{

	int total(getPrime());
	int n, c;

	while ((n = input()) != EOF)
	{
		c = input();
		
		printf("%d %d:", n, c);
		if (amountOfPrime[n] & 1)
		{
			if (( (c<<1) - 1) >= amountOfPrime[n])
				for (int i = 0; i < amountOfPrime[n]; i++)
					printf(" %d", prime[i]);
			else 
				for (int i = amountOfPrime[n] / 2 - c + 1; i <= amountOfPrime[n] / 2 + c - 1; i++)
				printf(" %d", prime[i]);
		}
		else
		{
			if (c<<1 >= amountOfPrime[n])
				for (int i = 0; i < amountOfPrime[n]; i++)
					printf(" %d", prime[i]);
			else
				for (int i = amountOfPrime[n] / 2 - c; i <= amountOfPrime[n] / 2 + c - 1; i++)
					printf(" %d", prime[i]);

		}

		putchar('\n');
		putchar('\n');
	}

	return 0;
}
int getPrime()
{
	int notPrime[N]{true, true};
	int count(1);
	for (int i = 2; i <= sqrt(N - 1); i++)
	{
		if (!notPrime[i])
		{
			for (int k = (N - 1) / i; k >= i; k--)
				if (!notPrime[k])
					notPrime[k*i] = true;
		}

	}

	for (int i = 2; i < N; i++)
	{

		if (!notPrime[i])
			prime[count++] = i;

		amountOfPrime[i] = count;

	}

	return count;
}
int input()
{
	char c;
	int num(0);
	while ((c = getchar()) != '\n'&&c != ' ')
	{
		if (c == EOF)
			return EOF;
		num = num * 10 + c - '0';
	}

	return num;

}