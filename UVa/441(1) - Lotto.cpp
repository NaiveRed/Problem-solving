#include<cstdio>

int main()
{
	int n;
	bool first(true);
	int num[15], ans[7];

	while (scanf("%d", &n) && n)
	{

		if (!first)
			putchar('\n');
		else
			first = false;

		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);

		for (int i = 0; i < n - 5; i++)
			for (int j = i + 1; j < n - 4; j++)
				for (int k = j + 1; k < n - 3; k++)
					for (int l = k + 1; l < n - 2; l++)
						for (int m = l + 1; m < n - 1; m++)
							for (int w = m + 1; w < n; w++)
								printf("%d %d %d %d %d %d\n", num[i], num[j], num[k], num[l], num[m], num[w]);

	}


	return 0;
}
