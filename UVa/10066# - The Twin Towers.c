#include<stdio.h>
#include<string.h>
#define N 105
#define max(x,y) (x)>(y)?x:y

int main(){

	int set = 1;
	int n1, n2;
	int s1[N], s2[N];
	int lcs[N][N];

	while (scanf("%d%d", &n1, &n2) != EOF && (n1 || n2))
	{

		memset(lcs, 0, sizeof(int)*N*N);

		int i;
		for (i = 1; i <= n1; i++)
			scanf("%d", &s1[i]);
		for (i = 1; i <= n2; i++)
			scanf("%d", &s2[i]);

		int j;

		for (i = 1; i <= n1; i++)
			for (j = 1; j <= n2; j++)
				lcs[i][j] = s1[i] == s2[j] ? lcs[i - 1][j - 1] + 1 : max(lcs[i - 1][j], lcs[i][j - 1]);

		printf("Twin Towers #%d\n", set++);
		printf("Number of Tiles : %d\n\n", lcs[n1][n2]);

	}

	return 0;
}