#include <cstdio>

int main()
{
	int Case;
	scanf("%d", &Case);
	for (int c = 1; c <= Case; c++)
	{
		int n, k, p;
		scanf("%d%d%d", &n, &k, &p);
		if ((k + p) % n)
			printf("Case %d: %d\n", c, (k + p) % n);
		else
			printf("Case %d: %d\n", c, n);
	}
	return 0;
}