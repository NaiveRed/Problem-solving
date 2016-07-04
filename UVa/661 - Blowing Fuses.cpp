#include<cstdio>

int main()
{
    bool state[21];
    int cost[21];
    int n, m, c, Case = 1;
    while (scanf("%d%d%d", &n, &m, &c) && (n || m || c))
    {
        int i, k, now = 0, max = 0;
        for (i = 1; i <= n; i++)
            state[i] = false;
        for (i = 1; i <= n; i++)
            scanf("%d", &cost[i]);

        for (i = 0; i < m; i++)
        {
            scanf("%d", &k);

            if (max != -1)
            {
                state[k] = !state[k];
                if (state[k])
                    now += cost[k];
                else
                    now -= cost[k];

                if (now <= c)
                {
                    if (now > max)
                        max = now;
                }
                else
                    max = -1;
            }
        }

        printf("Sequence %d\n", Case++);
        if (max == -1)
            puts("Fuse was blown.\n");
        else
        {
            puts("Fuse was not blown.");
            printf("Maximal power consumption was %d amperes.\n\n", max);
        }
    }

    return 0;
}