#include<cstdio>
#define MAX(a,b) ((a)>(b)?(a):(b))

//Maximum Sum Subarray
int main()
{
	int test;

	while (scanf("%d", &test) && test)
	{
		int num[10001]{};

		for (int i = 0; i < test; i++)
			scanf("%d", &num[i]);

		int sum(0), max_total(0);

		for (int n : num)
		{
			sum += n;
			if (sum <= 0)
				sum = 0;
			else
				max_total = MAX(max_total, sum);

		}

		if (max_total)
			printf("The maximum winning streak is %d.\n", max_total);
		else
			puts("Losing streak.");
	}


	return 0;
}
