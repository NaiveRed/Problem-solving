#include <cstdio>
#define N 62
#define B 61
typedef unsigned long long ULL;

int main()
{
    ULL dp[62][61];
    for (int i = 0; i < N; i++)
        dp[i][0] = dp[0][i] = dp[1][i] = 1; //back 是零的、n = 0 或 n = 1 的 都只會呼叫一次 trib

    for (int i = 2; i < N; i++)
        for (int j = 1; j < B; j++)
        {
            dp[i][j] = 1; // trib(i,j)
            // trib(k-i, j), k = 1 ~ j
            for (int k = 1; k <= j; k++)
                dp[i][j] += (i - k >= 0) ? dp[i - k][j] : 1; //小於零就只有一次
        }

    int n, back, Case = 1;
    while (scanf("%d%d", &n, &back) != EOF)
    {
        if (n > 60)
            break;
        printf("Case %d: %llu\n", Case++, n >= 0 ? dp[n][back] : 1);
    }

    return 0;
}