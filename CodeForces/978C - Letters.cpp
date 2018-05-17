#include <cstdio>
#define N 200005
typedef unsigned long long ULL;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    ULL dp[N] = {};

    for (int i = 1; i <= n; ++i)
    {
        scanf("%I64u", &dp[i]);
        dp[i] += dp[i - 1];
    }

    int dorm = 1;
    ULL b;
    for (int i = 0; i < m; ++i)
    {
        scanf("%I64u", &b);
        while (b > dp[dorm])
            ++dorm;
        printf("%d %I64u\n", dorm, b - dp[dorm - 1]);
    }

    return 0;
}
