#include<cstdio>
#include<climits>
#include<algorithm>
#define INF 1e13
using namespace std;
typedef long long LL;

int main()
{
    int n, m, k, tree[100], L[100][101];
    static LL dp[100][101][101];

    scanf("%d%d%d", &n, &m, &k);

    int i, j, a;
    for (i = 0; i < n; i++)
        scanf("%d", &tree[i]);

    for (i = 0; i < n; i++)
        for (j = 1; j <= m; j++)
            scanf("%d", &L[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j <= k; j++)
            for (a = 1; a <= m; a++)
                dp[i][j][a] = INF;

    if (tree[0])
        dp[0][1][tree[0]] = 0;
    else
        for (i = 1; i <= m; i++)
            dp[0][1][i] = L[0][i];

    for (i = 1; i < n; i++)//tree
        for (a = 1; a <= k; a++)//group
        {
            if (tree[i])
            {
                dp[i][a][tree[i]] = dp[i - 1][a][tree[i]];//與上一個同一顏色

                for (j = 1; j <= m; j++)//與上一個不同顏色
                {
                    if (j != tree[i])
                        dp[i][a][tree[i]] = min(dp[i][a][tree[i]], dp[i - 1][a-1][j]);
                }
            }
            else
            {
                for (j = 1; j <= m; j++)//與上一個同一顏色
                    dp[i][a][j] = dp[i - 1][a][j] + L[i][j];

                for (j = 1; j <= m; j++)//與上一個不同顏色
                {
                    for (int t = 1; t <= m; t++)
                        if (t != j)
                            dp[i][a][j] = min(dp[i][a][j], dp[i - 1][a - 1][t] + L[i][j]);
                }
            }
        }

    LL ans = INF;
    for (i = 1; i <= m; i++)
        ans = min(ans, dp[n - 1][k][i]);

    printf("%I64d\n", ans == INF ? -1 : ans);

    return 0;
}