#include<cstdio>
#include<algorithm>
#define N 101
using namespace std;

int main()
{
    int map[N], d[N][N], u, v, Case = 1;

    while (scanf("%d%d", &u, &v) && u&&v)
    {
        int i, j, k, idx = 0;
        for (i = 0; i < N; i++)
            fill(d[i], d[i] + N, 1e9);
        fill(map, map + N, 0);

        do
        {
            if (!map[u])
                map[u] = ++idx;
            if (!map[v])
                map[v] = ++idx;

            d[map[u]][map[v]] = 1;
        } while (scanf("%d%d", &u, &v) && u&&v);

        //Floyd-Warshall
        for (k = 0; k <= idx; k++)
            for (i = 0; i <= idx; i++)
                for (j = 0; j <= idx; j++)
                    if (i != j&&d[i][k] + d[k][j] < d[i][j])
                        d[i][j] = d[i][k] + d[k][j];

        int sum = 0, count = 0;
        for (i = 0; i <= idx; i++)
            for (j = 0; j <= idx; j++)
                if (d[i][j] < 1e9)
                {
                    sum += d[i][j];
                    count++;
                }

        printf("Case %d: average length between pages = %.3f clicks\n", Case++, (float)sum / count);
    }

    return 0;
}