#include <cstdio>
#define N 100
#define INF 1e3
int main()
{
    //freopen("test.out", "w", stdout);
    int T, d[N][N];

    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        int n, r, i, j, k;
        scanf("%d", &n);
        //init
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                d[i][j] = INF;
            d[i][i] = 0;
        }
        scanf("%d", &r);
        while (r--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            d[u][v] = d[v][u] = 1;
        }

        int s, goal, ans = 0;
        scanf("%d%d", &s, &goal);
        //Floyd Warshall
        for (k = 0; k < n; k++)
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    if (d[i][j] > d[i][k] + d[k][j])
                        d[i][j] = d[i][k] + d[k][j];

        //最久的
        for (i = 0; i < n; i++)
            if (ans < d[s][i] + d[i][goal])
                ans = d[s][i] + d[i][goal];

        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}