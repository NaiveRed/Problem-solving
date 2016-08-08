#include<cstdio>
#define DAY 1440

int main()
{
	int h1, h2, m1, m2;
	while (scanf("%d%d%d%d", &h1, &m1, &h2, &m2) && (h1 || h2 || m1 || m2))
	{
		int n1 = h1 * 60 + m1, n2 = h2 * 60 + m2, sum;
		if (n1 <= n2)
			sum = n2 - n1;
		else
			sum = DAY - n1 + n2;

		printf("%d\n", sum);
	}
	return 0;
}