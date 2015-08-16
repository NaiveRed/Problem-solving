#include<cstdio>
#include<cmath>
#define N 100000
#define M 50000

int prime[M];
bool sieve[N]{true, true};

inline int input();
inline void getPrime();
int main()
{
	getPrime();
	int Case(input());

	while (Case--)
	{

		int a(input()), b(input());
		int max(0), max_count(0);

		for (int i = a; i <= b; i++)
		{
			int total(1), temp(i);

			//短除法
			for (int j = 0; prime[j] <= temp&&prime[j]; j++)
			{
				int count(0);
				while (!(temp%prime[j]))
				{
					temp /= prime[j];
					count++;
				}

				total = total*(count + 1);//ex. 72=2^3 * 3^2  總共為 (3+1)*(2+1)
			}

			if (total > max_count)
			{
				max_count = total;
				max = i;
			}
		}

		printf("Between %d and %d, %d has a maximum of %d divisors.\n", a, b, max, max_count);

	}
	return 0;
}
int input()
{

	char c;
	int num(0);

	while ((c = getchar()) != ' '&&c != '\n')
		num = num * 10 + c - '0';

	return num;
}
void getPrime()
{
	int _sqrt = sqrt(N - 1);

	for (int i = 2; i < _sqrt; i++)
	{

		if (!sieve[i])
			for (int k = (N - 1) / i; k >= i; k--)
				if (!sieve[k])
					sieve[k*i] = true;
	}

	int count(0);
	for (int i = 0; i < N; i++)
	{
		if (!sieve[i])
			prime[count++] = i;
	}


}