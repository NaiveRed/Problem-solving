#include<cstdio>
#define N (1000000000>>2)

int dp[N + 1];
int main()
{
    for (int i = 1; i <= N; i++)
        dp[i] = dp[i >> 1] + 1;

    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n <= N)
            printf("%d\n", dp[n]);
        else if (n <= N << 1)
            printf("%d\n", dp[n >> 1] + 1);
        else
            printf("%d\n", dp[n >> 2] + 2);
    }

    return 0;
}