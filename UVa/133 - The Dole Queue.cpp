#include<cstdio>

bool list[21];

inline int input();
void last(int& flag, int& n);
void next(int& flag, int& n);
int main()
{

	int n;
	while (n = input())
	{
		int k = input();
		int m = input();

		bool first(true);

		for (int i = 1; i <= n; i++)//init
			*(list + i) = true;

		int flag1(1), flag2(n);

		int people(n);
		while (true)
		{
			if (first)
				first = false;
			else
				putchar(',');

			for (int i = 0; i < k - 1; i++)
				next(flag1, n);//下一個還未點過的，1 -> n
			for (int i = 0; i < m - 1; i++)
				last(flag2, n);//下一個還未點過的，n -> 1

			if (flag1 == flag2)
			{
				list[flag1] = false;
				printf("%3d", flag1);

				people--;
			}
			else
			{
				list[flag1] = list[flag2] = false;
				printf("%3d%3d", flag1, flag2);

				people -= 2;
			}

			if (!people)
			{
				putchar('\n');
				break;
			}

			next(flag1, n);
			last(flag2, n);
		}


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
void next(int& flag, int& n)
{
	flag++;
	if (flag > n)
		flag -= n;

	while (!list[flag])
	{
		flag++;
		if (flag > n)
			flag -= n;
	}
}
void last(int& flag, int& n)
{
	flag--;
	if (!flag)
		flag = n;

	while (!list[flag])
	{
		flag--;
		if (!flag)
			flag = n;
	}
}
