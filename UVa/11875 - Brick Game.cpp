#include <cstdio>

int main()
{
	int Case;
	scanf("%d", &Case);
	for (int c = 1; c <= Case; c++)
	{
		int n, ans;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int temp;
			scanf("%d", &temp);
			if (i == n / 2 + 1)
				ans = temp;
		}
		printf("Case %d: %d\n", c, ans);
	}

	return 0;
}