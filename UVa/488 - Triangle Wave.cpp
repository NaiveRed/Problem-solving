#include<cstdio>

int input();
int main()
{
	int Case=input();

	for (int i = 0;i<Case;i++)
	{
		getchar();
		int height = input();
		int f = input();

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
int input()
{
	int num(0);
	char c;

	while ((c = getchar()) != '\n')
		num = num * 10 + c - '0';

	return num;
}