#include<cstdio>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define N 101
#define M 10001

int main()
{
    int dp[M] = {};
    int square[N] = {}, i, j;

    for (j = 1; j < M; ++j)
        dp[j] = 10001;

    for (i = 1; i < N; ++i)
        square[i] = i*i;

    for (i = 1; i < N; ++i)
        for (j = square[i]; j < M; ++j)
            dp[j] = MIN(dp[j - square[i]] + 1, dp[j]);

    int n,Case;
    scanf("%d", &Case);
    while (Case--)
    {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }

    return 0;
}