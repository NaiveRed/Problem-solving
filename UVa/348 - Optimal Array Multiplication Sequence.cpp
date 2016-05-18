#include<cstdio>
#define N 11

int path[N][N];
void output(int i, int j);
int main()
{
    int d[N], n, dp[N][N],Case=0;
    while (scanf("%d", &n) && n)
    {
        Case++;
        int i, k;
        scanf("%d%d", &d[0], &d[1]);
        for (i = 2; i <= n; i++)
            scanf("%*d%d", &d[i]);

        for (i = 0; i <= n; i++)
            for (k = 0; k <= n; k++)
                dp[i][k] = 1e9;
        for (i = 1; i <= n; i++)
            dp[i][i] = 0;

        for (int dia = 1; dia < n; dia++)
        {
            for (i = 1; i <= n - dia; i++)
            {
                int j = i + dia;
                for (k = i; k < j; k++)
                {
                    int cost = dp[i][k] + dp[k + 1][j] + d[i - 1] * d[k] * d[j];
                    if (cost < dp[i][j])
                    {
                        path[i][j] = k;
                        dp[i][j] = cost;
                    }
                }
            }
        }

        printf("Case %d: ",Case);
        output(1, n);
        putchar('\n');
    }

    return 0;
}
void output(int i, int j)
{
    if (i == j)
        printf("A%d", i);
    else
    {
        int mid = path[i][j];
        putchar('(');
        output(i, mid);
        printf(" x ");
        output(mid + 1,j);
        putchar(')');
    }
}