#include<cstdio>

int main()
{

	inline int input();

	int Case = input();

	while (Case--)
	{
		bool delay[3651]{false};
		int day = input();
		int parties = input();

		for (int i = 0; i < parties; i++)
		{
			int parameter = input();
			for (int j = parameter; j <= day; j += parameter)
				if (!delay[j])
					delay[j] = true;

		}

		int count(0);
		for (int i = 1; i <= day; i++)
			if (delay[i])
			{
			delay[i] = false;

			if (i % 7 && i % 7 != 6)
				count++;

			}

		printf("%d\n", count);
	}


	return 0;
}
int input()
{
	char c;
	int num(0);

	while ((c = getchar()) != '\n')
		num = num * 10 + c - '0';

	return num;
}
