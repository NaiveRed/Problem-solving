#include<cstdio>
#define N 12
int main()
{
	int Case = 1,sum;
	int p[N], need[N];
	bool ans[N];
	while (scanf("%d", &sum) && sum >= 0)
	{
		int i;
		for (i = 0; i < 12; i++)
			scanf("%d", &p[i]);
		for (i = 0; i < 12; i++)
			scanf("%d", &need[i]);

		for (i = 0; i < 12; i++)
		{
			if (sum >= need[i])
			{
				sum -= need[i];
				ans[i] = true;
			}
			else
				ans[i] = false;

			sum += p[i];
		}

		printf("Case %d:\n", Case++);
		for (i = 0; i < 12; i++)
			puts(ans[i] ? "No problem! :D" : "No problem. :(");
	}

	return 0;
}