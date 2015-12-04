#include<cstdio>
#include<cstring>

int main()
{
	int group;
	char str[101];

	while (scanf("%d", &group) && group)//group為群組數，非群組有幾個字
	{
		getchar();//space
		gets(str);

		int len = strlen(str);
		int n = len / group;

		for (int i = 0; i < len; i += n)
			for (int j = i + n - 1; j >= i; j--)
				putchar(str[j]);

		putchar('\n');
	}

	return 0;
}
