#include<cstdio>

int input();
int main()
{
	int Case(0);
	double num;

	while ((num = input()) != EOF)
	{
		int count(0);
		while (num >= 2)
		{
			num /= 2;
			count++;
		}

		printf("Case %d: %d\n", ++Case, num == 1 ? count : count + 1);

	}

	return 0;
}
int input()
{
	char c;
	int num(0);
	while ((c = getchar()) != '\n')
	{
		if (c == '-')
			return EOF;

		num = num * 10 + c - '0';
	}

	return num;
}
