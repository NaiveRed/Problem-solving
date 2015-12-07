#include<cstdio>
#define N 40

int main()
{
	int fib[N]{1, 1};

	for (int i = 2; i < N; i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	int Case;
	scanf("%d", &Case);

	while (Case--)
	{
		int num;
		bool fib_base[N]{};

		scanf("%d", &num);

		int now = num, msb = 0;
		for (int i = N-1; i; i--)
			if (now >= fib[i])
			{
			now -= fib[i];
			fib_base[i] = true;
			if (!msb)
				msb = i;
			}
			else if (now <= 0)
				break;

		printf("%d = ", num);
		for (int i=msb; i; i--)
			printf("%d", fib_base[i]);
		puts(" (fib)");

	}

	return 0;
}