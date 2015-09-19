#include<cstdio>

int main()
{
	int Case;
	scanf("%d", &Case);

	while (Case--)
	{
		int empty,temp,require,count(0);
		
		scanf("%d%d%d", &empty, &temp, &require);
		
		empty += temp;

		while (empty >= require)
		{
			count += empty / require;
			empty = empty / require + empty%require;
		}

		printf("%d\n", count);
	}

	return 0;
}
