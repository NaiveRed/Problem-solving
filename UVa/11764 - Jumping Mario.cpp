#include<cstdio>

int input();
int main()
{
	int Case = input();

	for (int i = 1; i <= Case; i++)
	{
		int wall = input();

		int high(0), low(0);

		int now = input();
		while (--wall)
		{
			int next = input();

			if (now < next)
				high++;
			else if (now > next)
				low++;

			now = next;
		}

		printf("Case %d: %d %d\n", i, high, low);
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