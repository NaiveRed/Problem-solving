#include<cstdio>

int input();
int main()
{
	int Case = input();

	for (int i = 1; i <= Case; i++)
	{
		int n = input();

		int max = input();
		while (--n)
		{
			int num = input();
			if (num > max)
				max = num;
		}

		printf("Case %d: %d\n", i, max);
	}

	return 0;
}
int input()
{
	char c;
	int num(0);

	while ((c = getchar()) != '\n'&&c != ' ')
		num = num * 10 + c - '0';

	return num;
}