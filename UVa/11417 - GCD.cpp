#include<cstdio>

inline int GCD(int a, int b);
int main()
{
	int G[501]{};

	for (int N = 2; N < 501; N++)
	{
		G[N] += G[N-1];

		for (int i = 1; i <= N-1; i++)
			G[N] += GCD(i,N);
	}

	int num;
	while (scanf("%d", &num) && num)
		printf("%d\n", G[num]);

	return 0;
}
inline int GCD(int a, int b)
{
	int temp;

	while (b)
	{
		temp = b;
		b = a%b;
		a = temp;
	}

	return a;
}