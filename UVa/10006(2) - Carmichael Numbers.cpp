#include <cstdio>
#include <cstring>

int main()
{
	char carmichael[15][6] =
		{"561", "1105", "1729", "2465", "2821", "6601", "8911", "10585",
		 "15841", "29341", "41041", "46657", "52633", "62745", "63973"};

	char str[10], tmp[12] = "The number ";
	while (fgets(str, 10, stdin) && str[0] != '0')
	{
		int len = strlen(str), i;
		str[--len] = NULL;
		for (i = 0; i < 15; i++)
			if (!strcmp(str, carmichael[i]))
			{
				for (int i = 0; i < 11; i++)
					putchar(tmp[i]);
				for (int i = 0; i < len; i++)
					putchar(str[i]);
				puts(" is a Carmichael number.");

				break;
			}

		if (i == 15)
		{
			for (int i = 0; i < len; i++)
				putchar(str[i]);
			puts(" is normal.");
		}
	}

	return 0;
}