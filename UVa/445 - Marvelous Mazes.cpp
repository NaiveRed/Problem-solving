#include<cstdio>
#include<cctype>

int main()
{
	char c;
	while ((c = getchar()) != EOF)
	{

		if (c == '\n' || c == '!')
			putchar('\n');

		int times(0);
		while (isdigit(c))
		{
			times += c - '0';
			c = getchar();
		}

		while (times--)
			putchar(c == 'b' ? ' ' : c);

	}
	return 0;
}