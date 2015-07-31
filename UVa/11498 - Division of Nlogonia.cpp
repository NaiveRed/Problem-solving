#include<cstdio>

int main()
{
	int Case;
	while (scanf("%d", &Case) != EOF&&Case)
	{
		int p_x, p_y;
		scanf("%d%d", &p_x, &p_y);
		while (Case--)
		{
			int n, m;
			scanf("%d%d", &n, &m);

			if (n > p_x&&m > p_y)
				puts("NE");
			else if (n<p_x&&m>p_y)
				puts("NO");
			else if (n < p_x&&m < p_y)
				puts("SO");
			else if (n > p_x&&m < p_y)
				puts("SE");
			else
				puts("divisa");
		}

	}

	return 0;
}