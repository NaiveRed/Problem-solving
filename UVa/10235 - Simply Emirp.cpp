#include<cstdio>
#include<cmath>
#define N 1000000

bool notPrime[N];
void eratosthenes();
int main()
{
	eratosthenes();

	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (notPrime[n])
			printf("%d is not prime.\n", n);
		else
		{
			int rev = 0;

			for (int i = n; i; i /= 10)
				rev = rev * 10 + i % 10;

			if (notPrime[rev] || rev == n)
				printf("%d is prime.\n", n);
			else
				printf("%d is emirp.\n", n);
		}
	}

	return 0;
}
void eratosthenes()
{
	int _sqrt = sqrt(N - 1);

	for (int i = 2; i <= _sqrt; i++)
	{
		if (!notPrime[i])
		{
			for (int k = (N - 1) / i; k >= i; k--)
				if (!notPrime[k])
					notPrime[k*i] = true;
		}
	}
}