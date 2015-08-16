#include<cstdio>
#include<cmath>
#define N 1000000
#define MAX 1000000000000

int prime[N];
bool sieve[N]{true, true};
long long almostPrime[N];

inline long long input();
inline int getPrime();
inline int getAlmostPrime(int n);
int main()
{
	int n(getPrime());
	n=getAlmostPrime(n);

	int Case(input());

	while (Case--)
	{
		long long a(input()), b(input());
		int count(0);

		for (int i = 0; i < n; i++)
			if (almostPrime[i] >= a&&almostPrime[i] <= b)
				count++;
			
		printf("%d\n", count);

	}

	return 0;
}
long long input()
{
	char c;
	long long num(0);

	while ((c = getchar()) != ' '&&c != '\n')
		num = num * 10 + c - '0';

	return  num;
}
int getPrime()
{
	int _sqrt(sqrt(N - 1));
	for (int i = 2; i <= _sqrt; i++)
		
	{
		if (!sieve[i])
		{
			for (int k = (N - 1) / i; k >= i; k--)
				if (!sieve[k])
					sieve[k*i] = true;
		}

	}

	int count(0);
	for (int i = 0; i < N; i++)
		if (!sieve[i])
			prime[count++] = i;

	return count;
}
int getAlmostPrime(int n)
{
	int count(0);
	for (int i = 0;i<n; i++)
	{
		almostPrime[count] =(long long)prime[i] * prime[i];
		
		while (almostPrime[count++] < MAX)
			almostPrime[count] = almostPrime[count-1] *prime[i];
	
	}
	
	return count;
}