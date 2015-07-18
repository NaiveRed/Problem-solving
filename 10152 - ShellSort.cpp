#include<cstdio>
#include<cstring>

int main()
{
	int test;

	while (scanf("%d", &test) != EOF)
	{
		char origin[200][85], tar[200][85];

		while (test--)
		{
			int num;
			scanf("%d\r", &num);

			int i, j;
			for (i = 0; i < num; i++)//[0]為最上層
				gets(origin[i]);
			for (i = 0; i < num; i++)
				gets(tar[i]);

			i = j = num - 1;

			while (i >= 0)
			{
				/*
					1 3 2 4 5
					2 1 3 5 4
					理解:
					如果兩個都一樣(也就是相對上來說位置正確ex. 12345 和 14325 ，5都在3的後面這樣)，
					就繼續往上看，所以i,j都-1;
					如果不一樣，origin的就繼續向上看一不一樣(所以只有i--)，
					等到都找完，可以發現從tar[j]以上的烏龜都是還沒排好的，只要照順序讓他們往上爬即可。
				*/
				if (!strcmp(origin[i], tar[j]))
				{
					i--;
					j--;
				}
				else i--;
			}

			while (j >= 0)
				printf("%s\n", tar[j--]);

			puts("");
		}
	}

	return 0;
}