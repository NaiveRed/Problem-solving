#include<cstdio>
#include<algorithm>

int input();
void dfs(int x, int num);//x為水平位置,root為50

int leaf[100];
int main()
{
	int n, Case(0);
	while ((n = input()) != -1)
	{

		std::fill(leaf, leaf + 99, 0);

		dfs(50, n);//use dfs to build tree

		printf("Case %d:\n", ++Case);

		bool start(false);
		int i;
		for (i = 0; i < 100; i++)
			if (leaf[i])
				break;

		for (; i < 100 && leaf[i]; i++)
		{
			if (start)
				putchar(' ');
			else
				start = true;

			printf("%d", leaf[i]);
		}

		putchar('\n');
		putchar('\n');
	}

	return 0;
}
void dfs(int x, int num)
{
	leaf[x] += num;

	int n;

	n = input();
	if (n != -1)
		dfs(x - 1, n);

	n = input();
	if (n != -1)
		dfs(x + 1, n);
}
int input()
{
	char c;
	int num(0), neg(1);

	while ((c = getchar()) != '\n'&&c != ' ')
	{
		if (c == '-')
			neg = -1;
		else
			num = num * 10 + c - '0';
	}

	num *= neg;

	return num;
}
