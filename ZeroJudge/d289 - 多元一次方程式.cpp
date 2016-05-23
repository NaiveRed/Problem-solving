#include<cstdio>
#define N 8001

int main()
{
    int coe[8] = { 1, 13, 33, 43, 139, 169, 1309, 2597 };
    int i, j, dp[N] = {1}, n;
    for (i = 0; i < 8; i++)
        for (j = coe[i]; j < N; j++)
            dp[j] += dp[j - coe[i]];
    
    while (scanf("%d", &n) != EOF)
        printf("%d\n", dp[n]);

    return 0;
}