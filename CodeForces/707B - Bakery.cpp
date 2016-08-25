#include<cstdio>

int main()
{
    int n, m, k, i, j;
    scanf("%d%d%d", &n, &m, &k);

    static int u[100001], v[100001], len[100001];
    bool storages[100001] = { false };

    for (i = 0; i < m; i++)
        scanf("%d%d%d", &u[i], &v[i], &len[i]);

    for (i = 0; i < k; i++)
    {
        scanf("%d", &j);
        storages[j] = true;
    }

    int ans = -1;
    for (i = 0; i < m; i++)
    {
        if (storages[u[i]] != storages[v[i]])
            if (ans == -1)
                ans = len[i];
            else if (ans > len[i])
                ans = len[i];
    }

    printf("%d\n", ans);

    return 0;
}