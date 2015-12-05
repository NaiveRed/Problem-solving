#include<cstdio>

int main()
{
	int money[11]{5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

	long long method[30001]{1};
	long long n;

	for (int i = 0; i < 11; i++)
		for (n = money[i]; n <= 30000; n++)
			method[n] += method[n - money[i]];

	int digit1, digit2;
	while (scanf("%d.%d", &digit1, &digit2) && (digit1 || digit2))
		printf("%3d.%02d%17lld\n", digit1, digit2, method[digit1 * 100 + digit2]);

	return 0;
}