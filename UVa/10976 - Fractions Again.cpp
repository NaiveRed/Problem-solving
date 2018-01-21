#include <cstdio>

int main()
{
	int k, x[10001], y[10001];
	while (scanf("%d", &k) != EOF)
	{
		int count = 0;
		for (int i = k + 1; i <= 2 * k; i++)
		{
			if ((i * k) % (i - k) == 0)
			{
				x[count] = (i * k) / (i - k);
				y[count++] = i;
			}
		}

		printf("%d\n", count);
		for (int i = 0; i < count; i++)
			printf("1/%d = 1/%d + 1/%d\n", k, x[i], y[i]);
	}

	return 0;
}