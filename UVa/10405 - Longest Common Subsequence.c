#include<stdio.h>
#include<string.h>
#define N 1002
#define MAX(x,y) ((x)>(y)?x:y)

int lcs[N][N];
int main(){

	char s1[N], s2[N];

	while (gets(s1))
	{
		gets(s2);

		int len1 = strlen(s1), len2 = strlen(s2);
		int i, j;

		for (i = 1; i <= len1; i++)
			for (j = 1; j <= len2; j++)
				lcs[i][j] = s1[i-1] == s2[j-1] ? lcs[i - 1][j - 1] + 1 : MAX(lcs[i - 1][j], lcs[i][j - 1]);

		printf("%d\n", lcs[len1][len2]);

		memset(lcs, 0, sizeof(int)*N*N);
	}

	return 0;
}