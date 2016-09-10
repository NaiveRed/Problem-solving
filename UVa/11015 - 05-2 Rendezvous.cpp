#include<cstdio>

int main()
{
    int n, m, Case = 1;
    char name[23][12];
    int d[23][23];
    while (scanf("%d%d", &n, &m) && n)
    {
        getchar();
        int i, j, k;
        for (i = 1; i <= n; i++)
            fgets(name[i], 12, stdin);

        int u, v, w;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                d[i][j] = 1e9;

        for (i = 1; i <= n; i++)
            d[i][i] = 0;

        for (i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            d[u][v] = d[v][u] = w;
        }


        for (k = 1; k <= n; k++)
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    if (d[i][k] + d[k][j] < d[i][j])
                        d[i][j] = d[i][k] + d[k][j];

        int min = 1e9, ans;
        for (i = 1; i <= n; i++)
        {
            int cost = 0;
            for (j = 1; j <= n; j++)
                cost += d[i][j];

            if (cost < min)
            {
                min = cost;
                ans = i;
            }
        }

        printf("Case #%d : %s", Case++, name[ans]);
    }

    return 0;
}