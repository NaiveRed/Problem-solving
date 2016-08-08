#include<cstdio>

int main()
{
	int A, L;
	int Case = 0;
	while (scanf("%d%d", &A, &L) && A >= 0)
	{
		int count = 1;
		long long n = A;
		while (n != 1 )
		{
			if (n & 1)
				n = 3 * n + 1;
			else
				n >>= 1;
			if (n > (long long)L)
				break;
			count++;
		}

		printf("Case %d: A = %d, limit = %d, number of terms = %d\n", ++Case, A, L, count);
	}

	return 0;
}