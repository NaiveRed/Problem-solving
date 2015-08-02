/*
time: 0.029ms
*/
#include<cstdio>

int main()
{

	int num;
	bool first(true);

	while (scanf("%d", &num) && num)
	{
		if (first)
			first = false;
		else puts("");

		int limit(98765 / num);
		bool noSolution(true);

		for (int i = 1234; i <= limit; i++)
		{
			bool digit[10]{0};
			int temp1(i*num), temp2(i);

			if (temp1 < 10000)
				continue;

			bool isOk(true);

			if (temp2 < 10000)
				digit[0] = true;

			while (temp1)
			{
				if (digit[temp1 % 10])
				{
					isOk = false;
					break;
				}
				else digit[temp1 % 10] = true;

				temp1 /= 10;
			}
			while (temp2)
			{
				if (digit[temp2 % 10])
				{
					isOk = false;
					break;
				}
				else digit[temp2 % 10] = true;

				temp2 /= 10;
			}

			if (isOk)
			{
				if (noSolution)noSolution = false;

				printf("%d / %05d = %d\n", i*num, i, num);
			}

		}
		if (noSolution)
			printf("There are no solutions for %d.\n", num);


	}

	return 0;
}