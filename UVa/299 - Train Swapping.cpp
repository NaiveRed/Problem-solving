#include<cstdio>
#include<algorithm>

int main()
{

	int Case;

	scanf("%d", &Case);

	while (Case--)
	{
		int train[51]{0}, len, count(0);

		scanf("%d", &len);

		for (int i = 0; i < len; i++)
			scanf("%d", &train[i]);

		for (int i = 0; i < len ; i++)
			for (int j = 0; j < len - 1 - i; j++)
				if (train[j]>train[j + 1])
				{
			std::swap(train[j], train[j+1]);
			count++;
				}
		
		printf("Optimal train swapping takes %d swaps.\n", count);

	}

	return 0;
}