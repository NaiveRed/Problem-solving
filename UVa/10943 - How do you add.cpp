#include <cstdio>
#define M 200
#define MOD 1000000
int main()
{
	int C[M][M] = {};
	for (int i = 0; i < M; i++)
		C[i][0] = 1;
	for (int i = 1; i < M; i++)
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;

	int n, k;
	while (scanf("%d%d", &n, &k) && (n || k))
		printf("%d\n", C[n + k - 1][n]);

	return 0;
}