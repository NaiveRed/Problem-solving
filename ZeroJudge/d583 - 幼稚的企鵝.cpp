#include<stdio.h>

int main()
{
	int n;

	while (scanf("%d", &n) != EOF)
	{
		getchar();
		while (getchar() != '\n');

		for (int i = 1; i < n; i++)
			printf("%d ", i);

		printf("%d\n", n);
	}

	return 0;
}