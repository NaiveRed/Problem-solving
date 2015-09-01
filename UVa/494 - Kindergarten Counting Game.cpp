#include<cstdio>
#include<cctype>

int main()
{
	char c;
	int count(0);
	bool flag(false);

	while ((c = getchar())!=EOF)
	{
		if (c == '\n')
		{
			printf("%d\n", count);

			count = 0;
			flag = false;
			continue;
		}

		if (isalpha(c))
		{
			if (!flag)
			flag = true;
		}
		else if (flag)
		{
			count++;
			flag = false;
		}

	}

	return 0;
}
