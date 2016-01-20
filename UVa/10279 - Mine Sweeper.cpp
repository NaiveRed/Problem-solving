#include<cstdio>

char map[12][12] = {};

int getMine(int x, int y);
int main()
{
	int Case;
	scanf("%d", &Case);

	char touch[12][12] = {};
	
	for (int k = 0; k < Case; k++)
	{
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			getchar();
			for (int j = 1; j <= n; j++)
				map[i][j] = getchar();
		}

		bool isTouch = false;
		for (int i = 1; i <= n; i++)
		{
			getchar();
			for (int j = 1; j <= n; j++)
			{
				if ((touch[i][j] = getchar()) == 'x')
					if (map[i][j] == '*')
						isTouch = true;
			}
		}

		if (k)
			putchar('\n');

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (isTouch&&map[i][j] == '*')
					putchar('*');
				else if (touch[i][j] == 'x')
					putchar('0' + getMine(i, j));
				else
					putchar('.');
			}

			putchar('\n');
		}

		//init
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] = NULL;
			
	}

	return 0;
}
int getMine(int x, int y)
{
	int count = 0;
	for (int i = -1; i <= 1; i++)
	{
		if (i&&map[x + i][y] == '*')
			count++;
		if (map[x + i][y - 1] == '*')
			count++;
		if (map[x + i][y + 1] == '*')
			count++;
	}

	return count;
}