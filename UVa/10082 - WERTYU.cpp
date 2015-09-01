#include<cstdio>

int main()
{

	char keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

	char c;
	while ((c = getchar())!=EOF)
	{
		if (c == ' ' || c == '\n')
		{
			putchar(c);
			continue;
		}

		for (int i = 0;; i++)
		{
			if (keyboard[i + 1] == c)
			{
				putchar(keyboard[i]);
				break;
			}
		}

	}

	return 0;
}