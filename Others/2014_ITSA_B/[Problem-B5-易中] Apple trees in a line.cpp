#include<cstdio>
#define N 400000

int num[N];
int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		int i, max = 0, now = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &num[i]);
		for (i = 0; i < n; i++)
		{
			if (now + num[i] < 0)
			{
				now = 0;
				continue;
			}

			now += num[i];
			if (max < now)
				max = now;
		}

		printf("%d\n", max);

	}

	return 0;
}