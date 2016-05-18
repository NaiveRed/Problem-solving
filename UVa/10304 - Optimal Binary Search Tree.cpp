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
        for (i = 1; i <= n; i++)//��K�p�⥪�k�l�𬰪Ůɪ����p
            dp[i][i - 1] = 0;
        dp[n + 1][n] = 0;

        //�p��϶��M
        int sum[N] = {};
        for (i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + fre[i];

        //�϶�DP
        for (int dia = 1; dia < n; dia++)
        {
            for (i = 1; i <= n - dia; i++)
            {
                int j = i + dia;
                int cost = sum[j] - sum[i - 1];//k�I���j�M�ɶ��A�ݴ�ڤ~�����`�I���j�M cost
                for (k = i; k <= j; k++)
                    if (dp[i][k - 1] + dp[k + 1][j] + cost - fre[k] < dp[i][j])
                        dp[i][j] = dp[i][k - 1] + dp[k + 1][j] + cost - fre[k];
            }
        }

        printf("%d\n", dp[1][n]);
    }

    return 0;
}
