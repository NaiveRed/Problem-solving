#include <cstdio>
#define N 10001
int main()
{
    int n;
    long long dp[N] = {1};
    for (int i = 1; i <= 21; i++)
    {
        int iii = i * i * i;
        for (int c = iii; c < N; c++)
            dp[c] += dp[c - i * i * i];
    }

    while (scanf("%d", &n) != EOF)
        printf("%lld\n", dp[n]);

    return 0;
}