#include<cstdio>

int main()
{
	int Case;

	scanf("%d", &Case);
	getchar();
	
	char str[10];

	while (Case--)
	{
		int flag(0);

		gets(str);
		
		if (str[0] == 'o')
			flag++;
		
		if (str[1] == 'n')
			flag++;

		if (str[2] == 'e')
			flag++;

		if (str[3] != '\0')
			puts("3");
		else
			puts(flag > 1 ? "1" : "2");
	}

	return 0;
}