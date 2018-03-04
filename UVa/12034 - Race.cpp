#include <cstdio>
#define MOD 10056
#define N 1001

int main()
{
    /*
    dp[n][m]: n 是總共幾匹馬，m 是總共多少名次
    e.g.
    dp[3][2] (3 匹馬，名次共有 2 名) = 6 => (13)2, 1(23), (23)1, 2(13), (12)3, 3(12)。 ()為並列
    dp[4][1] = 1 => (1234)
    
    dp[n][m] = 
    {
        1: if m = 1.
        [n-1][m-1] * m + [n-1][m] * m: if m > 1.
        [n-1][m-1] * m + 0: if n = m.                     
    }
    */
    static int dp[N][N] = {}, ans[N];
    ans[1] = dp[1][1] = 1;
    for (int i = 2; i < N; ++i)
    {
        ans[i] = dp[i][1] = 1;

        for (int j = 2; j <= i; j++)
            ans[i] += dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) * j) % MOD;
        ans[i] %= MOD;
    }

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d: %d\n", t,ans[n]);
    }

    return 0;
}