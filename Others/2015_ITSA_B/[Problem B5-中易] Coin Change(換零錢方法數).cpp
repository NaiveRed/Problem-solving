#include<cstdio>

int main()
{
    int coin[5] = { 1, 5, 10, 20, 50 };
    long long dp[15001] = { 1 };
    for (int i = 0; i < 5; i++)
        for (int j = coin[i]; j <= 15000; j++)
            dp[j] += dp[j - coin[i]];

    int Case, n;
    scanf("%d", &Case);
    while (Case--)
    {
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }

    return 0;
}