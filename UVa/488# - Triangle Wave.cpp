#include<cstdio>

int main()
{
	int Case;
	scanf("%d", &Case);

	for (int i = 0; i<Case; i++)
	{
		int height ,f;
		scanf("%d%d", &height, &f);

		for (int k = 0; k<f; k++)
		{
			if (i || k)
				putchar('\n');

			for (int h = 1; h <= height; h++)
			{
				for (int j = h; j; j--)
					putchar(h + '0');
				putchar('\n');
			}

			for (int h = height - 1; h; h--)
			{
				for (int j = h; j; j--)
					putchar(h + '0');
				putchar('\n');
			}

		}
	}

	return 0;
}
