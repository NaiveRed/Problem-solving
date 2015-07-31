#include<cstdio>
#include<cstdlib>
#define N 256

int main()
{

	int Case;
	char str[10005];

	scanf("%d", &Case);

	while (Case--)
	{
		int price[N]{0};

		int line;
		scanf("%d", &line);
		getchar();

		while (line--)
		{
			gets(str);
			price[str[0]+128] = atoi(str + 2);//char range:-128~127
		}

		scanf("%d", &line);
		getchar();

		long sum(0);
		while (line--)
		{
			gets(str);
			for (int i = 0;str[i];i++)
				sum += price[str[i]+128];
		}
		printf("%.2lf$\n", (double)sum / 100);

	}


	return 0;
}