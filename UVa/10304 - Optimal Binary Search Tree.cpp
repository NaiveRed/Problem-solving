#include<cstdio>
#define N 252

int main()
{
    int fre[N], n, dp[N][N];
    while (scanf("%d", &n)!=EOF)
    {
        int i, k;
        for (i = 1; i <= n; i++)
            scanf("%d", &fre[i]);

        for (i = 0; i <= n; i++)
            for (k = 0; k <= n; k++)
                dp[i][k] = 1e9;
        for (i = 1; i <= n; i++)
            dp[i][i] = 0;
        for (i = 1; i <= n; i++)//方便計算左右子樹為空時的情況
            dp[i][i - 1] = 0;
        dp[n + 1][n] = 0;

        //計算區間和
        int sum[N] = {};
        for (i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + fre[i];

        //區間DP
        for (int dia = 1; dia < n; dia++)
        {
            for (i = 1; i <= n - dia; i++)
            {
                int j = i + dia;
                int cost = sum[j] - sum[i - 1];//k點的搜尋時間，需減掉根才為此節點的搜尋 cost
                for (k = i; k <= j; k++)
                    if (dp[i][k - 1] + dp[k + 1][j] + cost - fre[k] < dp[i][j])
                        dp[i][j] = dp[i][k - 1] + dp[k + 1][j] + cost - fre[k];
            }
        }

        printf("%d\n", dp[1][n]);
    }

    return 0;
}
