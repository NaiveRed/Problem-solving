#include<cstdio>
#define N 50

int main()
{
	long long sum[N] = { 1 };
	long long fib[N] = { 0, 1 };
	long long male[N] = {};

	for (int i = 2; i < N; i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	for (int i = 1; i < N; i++)
	{
		male[i] = male[i - 1] + fib[i];
		sum[i] = sum[i - 1] + fib[i + 1];
	}

	int n;
	while (scanf("%d", &n) && n != -1)
	{
		printf("%lld %lld\n", male[n], sum[n]);
	}


	return 0;
}