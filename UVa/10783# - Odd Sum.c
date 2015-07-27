#include<stdio.h>

int main(){

	int set;

	while (scanf("%d", &set) != EOF)
	{
		int count;
		for (count = 1; count <= set; count++)
		{
			int a, b;

			scanf("%d", &a);
			scanf("%d", &b);

			int i, sum = 0;

			for (i = a; i <= b; i++)
				if (i % 2 == 1)
					sum += i;
			printf("Case %d: %d\n", count, sum);

		}

	}
	return 0;
}